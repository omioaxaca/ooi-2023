#include <bits/stdc++.h>

using namespace std;

struct Node {
  int idx;
  int w;

  bool operator<(const Node& rhs) const {
    return w > rhs.w;
  }
};
typedef vector<vector<Node>> Matrix;

const int INF = INT32_MAX;

void dijkstra(Node start, const Matrix& adj, vector<int>& distance, vector<int>& path) {
  priority_queue<Node> nodes;
  nodes.push(start);
  distance[start.idx] = 0;
  while (!nodes.empty()) {
    int u = nodes.top().idx;
    nodes.pop();

    for (const auto& n : adj[u]) {
      const int v = n.idx;
      const int w = n.w;

      if (distance[u] + w < distance[v]) {
        distance[v] = distance[u] + w;
        nodes.push({v, distance[v]});

        // The path to get to v now is through u
        path[v] = u;
      }
    }
  }
}

bool checkPath(int u, int k, const Matrix& adj, const vector<int>& distance, vector<bool>& visited) {
  // printf("Checking u=%d k=%d\n", u, k);
  if (u == -1 || visited[u]) {
    return false;
  }
  visited[u] = true;
  
  // If minimum distance to u is less than k then it may be possible to get here in exactly k steps.
  if (distance[u] <= k) {
    if (distance[u] % 2 == k % 2) {
      // If the parity of both is the same, then the chip can be moved back and forth between node u
      // and its parent in the path and eventually it will reach u in k steps.
      return true;
    }
    else {
      // We need to check other paths through the neighbors of u to see if it is possible to get to them in k - 1 steps.
      // If so, then it is possible to get to u in k steps.
      for (const auto& n : adj[u]) {
        int v = n.idx;
        if( checkPath(v, k - 1, adj, distance, visited) ) {
          // If any neighbor meets the criteria, we return true.
          return true;
        }
      }
    }
  }
  visited[u] = false;
  return false;
}

int main() {
  int numNodes;
  int numConnections;
  scanf("%d %d", &numNodes, &numConnections);
  Matrix adj(numNodes + 1); // 1-indexed
  for (int i = 0; i < numConnections; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back({v, 1});
    adj[v].push_back({u, 1});
  }
  
  vector<int> distance(numNodes + 1, INF);
  vector<int> path(numNodes + 1, -1);
  dijkstra({1, 0}, adj, distance, path);

  // for (int i = 1; i <= numNodes; ++i) {
  //   printf("v=%d dist=%d\n", i, distance[i]);
  // }
  // printf("\n");

  int numQuestions;
  scanf("%d", &numQuestions);
  while (numQuestions--) {
    int v;
    int k;
    scanf("%d %d", &v, &k);

    if (distance[v] == k) {
      printf("1\n");
    }
    else {
      vector<bool> visited(numNodes + 1, false);
      printf("%d\n", checkPath(v, k, adj, distance, visited));
    }
  }

  return 0;
}
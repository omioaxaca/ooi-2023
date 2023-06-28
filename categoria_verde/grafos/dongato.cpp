// Find total connected components.
// Use the matrix to create an undirected graph.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// Define data type for the adjacency list. Use a set to ensure all connections are unique.
typedef vector<unordered_set<int>> AdjList;

struct Position {
  int x, y;
};

int rows;
int columns;


int getNodeId(Position pos) {
  return pos.x * columns + pos.y;
}

Position getPosition(int nodeId) {
  return {nodeId / columns, nodeId % columns};
}



void createConnection(Position current, char c, AdjList& connections) {
  Position next = current;
  if (c == 'N') {
    next.x--;
  }
  else if (c == 'S') {
    next.x++;
  }
  else if(c == 'E') {
    next.y++;
  }
  else if(c == 'W') {
    next.y--;
  }
  // Check if next is valid
  if (next.x < 0 || next.x >= rows || next.y < 0 || next.y >= columns) {
    return;
  }

  // Create a bi-directional connection between current and next.
  int u = getNodeId(current);
  int v = getNodeId(next);
  connections[u].insert(v);
  connections[v].insert(u);
}


void dfs(int node, AdjList& connections, vector<bool>& visited) {
  if (visited[node]) {
    return;
  }
  visited[node] = true;
  for (int next : connections[node]) {
    dfs(next, connections, visited);
  }
}

int main() {
  
  cin >> rows >> columns;

  int numNodes = rows * columns;
  AdjList connections(numNodes);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      char c;
      cin >> c;
      createConnection({i, j}, c, connections);
    }
  }

  // Count connected components.
  int counter = 0;
  vector<bool> visited(numNodes, false);
  for (int i = 0; i < numNodes; ++i) {
    if (!visited[i]) {
      dfs(i, connections, visited);
      counter++;
    }
  }

  cout << counter << "\n";
}
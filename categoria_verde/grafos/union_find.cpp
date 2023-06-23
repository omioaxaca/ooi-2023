#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  public:
    DisjointSet(int numNodes) : parents(numNodes)
    {
      for (int i = 0; i < numNodes; ++i) {
        parents[i] = i;
      }
    }

    void Union(int a, int b) {
      parents[getRoot(a)] = getRoot(b);
    }

    bool Find(int a, int b) {
      return getRoot(a) == getRoot(b);
    }

  private:
    vector<int> parents;

    int getRoot(int node) {
      while (node != parents[node]) {
        node = parents[node];
      }
      return node;
    }

};

int main() {
  int numNodes;
  cin >> numNodes;
  DisjointSet ds(numNodes);

  // Preguntas.
  int a, b;
  ds.Union(a, b);
  if (ds.Find(a, b) == true) // conectado



  return 0;
}
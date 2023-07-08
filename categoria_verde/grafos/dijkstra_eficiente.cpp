// Implementacion Dijkstra con priotiry_queue
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int INF = INT32_MAX; // Un numero muy grande.

// Definir lista de adyacencia usando un nodo que contiene
// el valor del nodo asi como el costo.
struct Nodo {
  int id;
  int costo;

  friend bool operator<(Nodo a, Nodo b) {
    return a.costo < b.costo;
  }
};
vector<vector<Nodo>> adj;

std::vector<int> dijkstra(int numNodos, int origen) {
  // 1. Inicializar las distancias en INF. El arreglo representa la distancia minima para ir desde el origen hasta i.
  vector<int> distancia(numNodos, INF);
  distancia[origen] = 0; // La distancia al origen es 0.

  // Crear una cola con prioridad del costo menor.
  priority_queue<Nodo> pq;
  // Insertar el origen.
  pq.push({origen, 0});
  // Mientras haya nodos que no sean parte del SPT.
  while (!pq.empty()) {
    // 2. Buscar el nodo con la distancia menor que no este en el spt
    int u = pq.top().id;
    pq.pop();

    // 3. Para todos sus vecinos, intentar hacer la relajacion.
    for (Nodo n : adj[u]) {
      int v = n.id;
      int w = n.costo;

      if (distancia[u] + w < distancia[v]) {
        // Relajacion
        distancia[v] = distancia[u] + w;
        // Ahora agregar a la cola porque necesitamos explorar este nodo.
        pq.push({v, distancia[v]});
      }
    }
  }

  return distancia;
}

int main() {
  /* Ejemplo entrada
  5
  5
  0 1 3
  0 4 8
  1 2 2
  1 4 4
  2 4 1
  4
  */
  /* Resultado:
  nodos      =  0  1  2   3   4
  distancias = {6, 3, 1, INF, 0}
  */
  int numNodos;
  cin >> numNodos;
  adj.resize(numNodos);

  int numAristas;
  cin >> numAristas;
  while (numAristas--) {
    int u, v, w; // u=origen, v=destino, w=costo
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int origen;
  cin >> origen;

  auto distancia = dijkstra(numNodos, origen);
  cout << "Distancias minimas\n";
  for (int i = 0; i < distancia.size(); ++i) {
    cout << "Desde " << origen << " hasta " << i << ": " << distancia[i] << "\n";
  }


  return 0;
}
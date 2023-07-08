// Pseudocodigo Dijkstra
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = INT32_MAX; // Un numero muy grande.
const int numNodos = 1000;
int costos[numNodos][numNodos] = {0};

vector<int> distancia(numNodos);
set<int> spt; // Conjunto de nodos de los que ya se conoce su distancia minima.

int buscarMinimo() {
  int indiceMinimo;
  int minimo = INF;
  for (int i = 0; i < numNodos; ++i) {
    if (spt.find(i) != spt.end()) {
      // El nodo ya esta en el SPT, entonces lo saltamos.
      continue;
    }
    // Actualizar el minimo si encontramos uno menor.
    if (distancia[i] < minimo) {
      minimo = distancia[i];
      indiceMinimo = i;
    }
  }
  return indiceMinimo;
}

void dijkstra(int src) {
  // 1. Inicializar todo en inf
  for (int i = 0; i < numNodos; ++i) {
    distancia[i] = INF;
  }
  // La distancia al origen es 0.
  distancia[src] = 0;

  // Repetir numNodos veces
  for (int contador = 0; contador < numNodos; ++contador) {
    // 2. Buscar el nodo con la distancia menor que no este en el spt
    int u = buscarMinimo();
    // Agregar al spt
    spt.insert(u);

    // 3. Para todos sus vecinos, intentar hacer la relajacion.
    for (int v : vecinos(u)) {
      // Relajacion
      distancia[v] = min(distancia[v], distancia[u] + costo[u][v]);
    }
  }
}

int main() {
  // Leer matriz de adyacencia.

  return 0;
}
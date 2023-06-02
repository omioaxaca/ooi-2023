#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> ady;
stack<int> nodosOrdenados;

void topo(int nodo, vector<bool>& visitados) {
  // Marcar a este nodo como visitado.
  visitados[nodo] = true;

  // Ir a todas las conexiones del nodo.
  for (int v : ady[nodo]) {
    if (visitados[v]) {
      continue;
    }
    topo(v, visitados);
  }
  // En este punto la recursion ya ha regresado. Es decir, ya visitamos
  // todos los caminos posibles que genera el nodo actual. Ahora, podemos
  // agregar este nodo a la lista ordenada.
  nodosOrdenados.push(nodo);
}







vector<int> maximos();// dp
int get_max(int nodo, vector<bool>& visitados) {
  visitado[nodo] = true;
  if (maximos[nodo] != -1) {
    return maximos[nodo];
  }
  if (/*no conexiones*/) {
    return valor[nodo];
  }
  // Para todas las conexxiones
  int maxi = 0;
  for (v : conexiones) {
    maxi = max(max, get_max(v, visitados));
  }
  visitado[nodo] = false;
  maximos[nodo] = maxi;
  return maxi;

}








int main() {
  int numNodos; // vertices
  cin >> numNodos;
  
  ady.resize(numNodos);

  int numConexiones; // aristas
  cin >> numConexiones;

  for (int i = 0; i < numConexiones; ++i) {
    int u, v;
    cin >> u >> v;
    // Hay una conexion de u a v
    ady[u].push_back(v);
  }

  // Nodos visitados
  vector<bool> visitados(false);

  for (int i = 0; i < numNodos; ++i) {
    if (!visitados[i]) {
      topo(i, visitados);
    }
  }

  while (!nodosOrdenados.empty()) {
    cout << nodosOrdenados.top() << " ";
    nodosOrdenados.pop();
  }



  return 0;
}
// Resolucion usando BFS con estado de varias variables.
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
using namespace std::rel_ops;

struct Posicion {
  int x, y;

  // Definir el operador == para el tipo Posicion.
  friend bool operator==(Posicion a, Posicion b) {
    return a.x == b.x && a.y == b.y;
  }
  // Definir el operador < para el tipo Posicion.
  friend bool operator<(Posicion a, Posicion b) {
    if (a.x == b.x) {
      return a.y < b.y;
    }
    return a.x < b.x;
  }
};

struct Estado {
  Posicion var1, var2;
  int t;
};

int n; // limite matrix
char mapa[51][51] = {0};
// Crear un set para guardar los estados visitados.
set<pair<Posicion, Posicion>> visitados;

vector<Estado> obtenerEstadosSiguientes(Estado actual) {
  vector<Estado> siguientes;
  // Explorar los posibles movimientos (estados que se derivan de este).
  vector<int> movs_x = {0, -1, 0, 1};
  vector<int> movs_y = {-1, 0, 1, 0};

  // Simular movimientos para var1
  for (int i = 0; i < 4; ++i) {
    Posicion siguiente = actual.var1;
    siguiente.x += movs_x[i];
    siguiente.y += movs_y[i];

    // Determinar si el estado siguiente es valido.
    if (siguiente.x < 0 || siguiente.x > n || siguiente.y < 0 || siguiente.y > n) {
      // Estamos fuera de la matriz.
      continue;
    }
    if (mapa[siguiente.x][siguiente.y] == '#') {
      // Estamos en una celda bloqueada.
      continue;
    }
    // Revisar si es posible moverse a una celda con fuego.
    if (mapa[siguiente.x][siguiente.y] == '*') {
      if (mapa[actual.var2.x][actual.var2.y] != 'B') {
        // Estamos sobre una celda con fuego y la otra variable no esta sobre el boton.
        continue;
      }
    }
    // Revisar si no he visitado el estado.
    if (visitados.find({actual.var2, siguiente}) != visitados.end()) {
      // Ya lo visite
      continue;
    }
    if (visitados.find({siguiente, actual.var2}) != visitados.end()) {
      // Ya lo visite
      continue;
    }
    // Marcar este estado como visitado.
    visitados.insert({actual.var2, siguiente});
    visitados.insert({siguiente, actual.var2});

    // En este punto ya sabemos que el movimiento es valido.
    siguientes.push_back({siguiente, actual.var2, actual.t + 1});
  }
}

// Regresa la minima cantidad de pasos para que Marios y Luigi lleguen a la salida.
int bfs(Posicion mario, Posicion luigi, Posicion salida) {
  // Guardar el estado inicial.
  queue<Estado> estados;
  Estado inicio = {mario, luigi, 0};
  estados.push(inicio);

  // Marcar el estado inicial como visitado
  visitados.insert({inicio.var1, inicio.var2});
  visitados.insert({inicio.var2, inicio.var1});

  while (!estados.empty()) {
    Estado actual = estados.front();
    estados.pop();

    // Verificar si ya llegamos a la solucion.
    if (actual.var1 == salida && actual.var2 == salida) {
      return actual.t;
    }

    // Obtener estados derivados del actual cuando var1 se mueve.
    if (actual.var1 != salida) {
      auto estadosVar1 = obtenerEstadosSiguientes({actual.var1, actual.var2, actual.t});
      for (auto estado : estadosVar1) {
        estados.push(estado);
      }
    }
    // Obtener estados derivados del actual cuando var2 se mueve.
    if (actual.var2 != salida) {
      auto estadosVar2 = obtenerEstadosSiguientes({actual.var2, actual.var1, actual.t});
      for (auto estado : estadosVar2) {
        estados.push(estado);
      }
    }
  }
  return -1;
}

int main() {


  return 0;
}
// https://omegaup.com/arena/problem/L-OMI-Super-Agente/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int TAM_MAX = 2000;
const int INF = INT32_MAX; // El numero mas grande que se puede representar en un entero.

// Crear una matriz para representar el mapa e inicializar en 0.
int mapa[TAM_MAX][TAM_MAX] = {0};
int filas, columnas;

struct Estado {
  int f;
  int c;
  int pasos;
};

void simular(vector<Estado> guardias) {
  queue<Estado> estados;
  for (int i = 0; i < guardias.size(); ++i) {
    estados.push(guardias[i]);
  }
  
  while (!estados.empty()) {
    Estado actual = estados.front();
    estados.pop();

    // En el agoritmo de BFS, normalmente en este punto revisamos
    // si ya hemos llegado al destino. Sin embargo, en este problema
    // nos interesa recorrer todas las posibilidades.

    // Revisar todas las posibilidades.
    vector<int> movs_f = {-1, 1,  0, 0};
    vector<int> movs_c = { 0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      Estado siguiente;
      siguiente.f = actual.f + movs_f[i];
      siguiente.c = actual.c + movs_c[i];
      siguiente.pasos = actual.pasos + 1;

      // Verificar si el estado siguiente es valido
      // Revisar que no estemos fuera de los limites de la matriz.
      if (siguiente.f < 0 || siguiente.f >= filas || siguiente.c < 0 || siguiente.c >= columnas) {
        // Estado fuera de la matriz.
        continue;
      }
      // Revisar si la casilla ha sido visitada en una cantidad menor de pasos.
      if (mapa[siguiente.f][siguiente.c] < siguiente.pasos) {
        continue;
      }
      // Marcar esta posicion como visitada. Al mismo tiempo, marcar la cantidad de pasos que tomo
      // para llegar hasta aqui.
      mapa[siguiente.f][siguiente.c] = siguiente.pasos;
      estados.push(siguiente);
    }
  }
}

void imprimir_mapa() {
  printf("------------------------------\n");
  for (int f = 0; f < filas; ++f) {
    for (int c = 0; c < columnas; ++c) {
      printf("\t%d ", mapa[f][c]);
    }
    printf("\n");
  }
  printf("------------------------------\n");
}

int main() {
  cin >> filas >> columnas;
  vector<Estado> guardias;
  for (int f = 0; f < filas; ++f) {
    for (int c = 0; c < columnas; ++c) {
      char k;
      // Leer el mapa y guardar la informacion en la matriz.
      cin >> k;
      if (k == '.') {
        mapa[f][c] = INF; // Representar que se puede caminar sobre esta casilla.
      }
      if (k == '#') {
        mapa[f][c] = -1; // Marcar casilla como no valida para caminar.
      }
      if (k == 'G') {
        mapa[f][c] = 0;
        Estado guardia = {f, c, 0}; // Crear un guardia.
        guardias.push_back(guardia); // Insertar el guardia en el vector.
      }
    }
  }
  // cout << "Mapa original" << endl;
  // imprimir_mapa();
  // for (int i = 0; i < guardias.size(); ++i) {
  //   simular(guardias[i]);
  //   // cout << "Mapa despues del guardia " << i << endl;
  //   // imprimir_mapa();
  // }
  simular(guardias);

  // Buscar la posicion con el numero mas grande.
  int mayor = 0;
  for (int f = 0; f < filas; ++f) {
    for (int c = 0; c < columnas; ++c) {
      mayor = max(mayor, mapa[f][c]);
    }
  }
  cout << mayor << endl;

  return 0;
}
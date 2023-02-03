// Busqueda en amplitud

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int TAM_MAX = 10000;

int mapa[TAM_MAX][TAM_MAX] = {0};
int filas;
int columnas;

// Declarar un nuevo tipo de dato que almacena la posicion (f,c) y la cantidad de pasos.
struct Estado {
  int f;
  int c;
  int pasos;
};

// Regresa la cantidad minima de pasos para llegar del estado inicial al final.
int buscarSalida(Estado inicial, Estado final) {
  // Declarar una cola para guardar los estados.
  queue<Estado> estados;
  // Insertar en la cola el estado inicial.
  estados.push(inicial);

  while (!estados.empty()) {
    // Sacar un elemento del frente de la cola.
    Estado actual = estados.front();
    estados.pop(); // Borrar este elemento de la cola.

    // Verificar si este estado es igual al estado final.
    if (actual.f == final.f && actual.c == final.c) {
      // Ya se encontro la solucion. Se regresa la cantidad de pasos
      return actual.pasos;
    }

    // Evaluar todas las posibilidades.
    //    Declarar arreglos con los movimientos posibles.
    vector<int> movs_f = {-1, 1,  0, 0};
    vector<int> movs_c = { 0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      Estado siguiente;
      siguiente.f = actual.f + movs_f[i];
      siguiente.c = actual.c + movs_c[i];
      siguiente.pasos = actual.pasos + 1;

      // Verificar si la posibilidad es valida.
      // Verificar que estemos dentro de los limites de la matriz.
      if (siguiente.f < 0 || siguiente.f >= filas || siguiente.c < 0 || siguiente.c >= columnas) {
        // No es valido.
        continue;
      }
      // Validar si es una posicion libre.
      if (mapa[siguiente.f][siguiente.c] != 0) {
        // No es valido.
        continue;
      }
      // Esta es una opcion valida, entonces se mete a la cola.
      estados.push(siguiente);
      // Marcarlo como visitado.
      mapa[siguiente.f][siguiente.c] = 1;
    }
  }

  // Si el algoritmo llega a este punto, entonces no se encontro solucion.
  return -1;
}

int main() {
  cin >> filas >> columnas;

  for (int f = 0; f < filas; ++f) {
    for (int c = 0; c < columnas; ++c) {
      cin >> mapa[f][c];
    }
  }

  // Declarar el estado inicial.
  Estado inicio;
  inicio.pasos = 0;

  // Leer las coordenadas de inicio y final
  cin >> inicio.f >> inicio.c;
  Estado fin;
  cin >> fin.f >> fin.c;

  // Invocar la busqueda.
  int cantidadDePasos = buscarSalida(inicio, fin);
  if (cantidadDePasos == -1) {
    cout << "No hay salida" << endl;
  }
  else {
    cout << "La cantidad minima de pasos es: " << cantidadDePasos << endl;
  }

  return 0;
}
// Cutting sticks
// https://onlinejudge.org/external/100/10003.pdf
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int memoria[50][50];

// Regresa el minimo de los cortes posibles entre los indices.
int cortar(int indiceInicio, int indiceFin, const vector<int>& cortes) {
  // Revisar casos base
  // Si ya no hay cortes por hacer, entonces se acaba.
  if (indiceFin - indiceInicio <= 1) {
    return 0;
  }
  if (memoria[indiceInicio][indiceFin] != 0) {
    return memoria[indiceInicio][indiceFin];
  }

  // El costo de cortar la barra actual es igual al tamanio de la barra actual.
  int costoCorte = cortes[indiceFin] - cortes[indiceInicio];
  // Iniciar un acumulador para el minimo costo posible, inicializado a un valor muy grande.
  int minCostoCortes = INT32_MAX;
  // Probar las opciones en donde se puede hacer un corte.
  for (int corte = indiceInicio + 1; corte < indiceFin; ++corte) {
    int costoCortesIzq = cortar(indiceInicio, corte, cortes);
    int costoCortesDer = cortar(corte, indiceFin, cortes);
    int costoTotal = costoCorte + costoCortesIzq + costoCortesDer;
    minCostoCortes = min(minCostoCortes, costoTotal);
  }
  // Guardar en la memoria y regresar.
  memoria[indiceInicio][indiceFin] = minCostoCortes;
  return memoria[indiceInicio][indiceFin];
}


int main() {
  int longitud;
  int cantidadCortes;

  while(cin >> longitud && longitud != 0) {
    // Reiniciar la memoria
    memset(memoria, 0, sizeof(memoria));

    // Leer los datos
    cin >> cantidadCortes;
    vector<int> cortes;
    // Agrego los limites de la barra.
    cortes.push_back(0); // Inicio
    for (int i = 0; i < cantidadCortes; ++i) {
      int corte;
      cin >> corte;
      cortes.push_back(corte);
    }
    cortes.push_back(longitud); // Final de la barra

    cout << "The minimum cutting is " << cortar(0, cortes.size() - 1, cortes) << "." << endl;
  }

  return 0;
}
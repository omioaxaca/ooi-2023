// Cutting sticks
// https://onlinejudge.org/external/100/10003.pdf
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> cortes, int longitud) {
  int pivote = rand();
  vector<int> izquierda;
  for (int i = 0; i < pivote; ++i) {
    izquierda.push_back(cortes[i]);
  }
  vector<int> derecha;
  for (int i = pivote; i < cortes.size(); ++i) {
    derecha.push_back(cortes[i]);
  }
  solve(izquierda, longitud - pivote);
  solve(derecha, pivote);
}


int cortar(int indiceInicio, int indiceFin) {
  // Revisar casos base
  // Si ya no hay cortes por hacer, entonces se acaba.
  if (indiceFin - indiceInicio <= 1) {
    return 0;
  }

  // Probar las posibilidades.
  // Elegir un pivote para hacer el corte.
  for (int pivote = indiceInicio + 1; pivote < indiceFin; ++pivote) {
    cortar(indiceInicio, pivote);
    cortar(pivote, indiceFin);
  }
}


void imprimir(vector<int>& v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  int longitud;
  int cantidadCortes;

  cin >> longitud;
  cin >> cantidadCortes;
  vector<int> cortes(cantidadCortes);

  for (int& corte : cortes) {
    cin >> corte;
  }

  do {
    imprimir(cortes);
  } while(next_permutation(cortes.begin(), cortes.end()));


  return 0;
}
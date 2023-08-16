#include <bits/stdc++.h>

using namespace std;

// Contar en el rango dado [ini, fin] las ocurrencias de y
// Complejidad lineal O(n)
int obtenerOcurrencias(int y, int ini, int fin, vector<int>& numeros) {
  int ocurrenciasY = 0;
  for (int j = ini; j <= fin; ++j) {
    if (numeros[j] == y) {
      ocurrenciasY++;
    }
  }
  return ocurrenciasY;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> numeros(n);
  for (int i = 0; i < n; ++i) {
    cin >> numeros[i];
  }
  int k;
  cin >> k;

  int contador = 0;
  for (int i = 0; i < n; ++i) {
    int x = numeros[i];
    int y = k - x;
    // Buscar cuantas veces aparece Y en los numeros anteriores.
    int ocurrenciasY = obtenerOcurrencias(y, 0, i - 1, numeros);
    // El contador de parejas incrementa de acuerdo a la cantidad
    // de ocurrencias de y que encontramos.
    contador += ocurrenciasY;
  }

  cout << contador << "\n";

  return 0;
}
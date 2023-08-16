#include <bits/stdc++.h>

using namespace std;

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
    cout << "posicion: " << i << " x: " << x << endl;
    int y = k - x;
    // Buscar cuantas veces aparece Y en los numeros anteriores.
    int ocurrenciasY = 0; // Contar cuantas veces aparece y
    for (int j = 0; j < i; ++j) {
      if (numeros[j] == y) {
        ocurrenciasY++;
      }
    }
    cout << "Ocurrencias de " << y  << ": " << ocurrenciasY << endl;
    // El contador de parejas incrementa de acuerdo a la cantidad
    // de ocurrencias de y que encontramos.
    contador += ocurrenciasY;
  }

  cout << contador << "\n";

  return 0;
}
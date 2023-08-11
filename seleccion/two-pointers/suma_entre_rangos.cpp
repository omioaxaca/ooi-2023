#include <bits/stdc++.h>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int cantidadNumeros;
  cin >> cantidadNumeros;

  vector<int> numeros(cantidadNumeros);
  for (int i = 0; i < cantidadNumeros; ++i) {
    cin >> numeros[i];
  }

  int izq;
  int der;
  cin >> izq >> der;

  int suma = 0;
  for (int i = izq; i <= der; ++i) {
    suma += numeros[i];
  }
  cout << suma;


  return 0;
}
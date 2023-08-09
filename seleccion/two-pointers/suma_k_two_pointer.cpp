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

  // Ordenar los numeros de menor a mayor.
  sort(numeros.begin(), numeros.end());

  // Usar two pointers para calcular las sumas posibles
  int izq = 0;
  int der = n - 1;
  bool encontrado = false;
  while (izq < der) {
    int suma = numeros[izq] + numeros[der];
    if (suma == k) {
      encontrado = true;
      break;
    }
    else if (suma > k) {
      // Si la suma es mayor que k, entonces la unica forma
      // de hacer la suma menor es disminuir el valor del apuntador de la derecha
      // porque los numeros estan ordenados de menor a mayor.
      der--;
    }
    else {
      // Si la suma es menor, la unica forma de incrementarla
      // es incrementar el valor del apuntador de la izquierda.
      izq++;
    }
  }

  if (encontrado) {
    cout << "Si";
  }
  else {
    cout << "No";
  }



  return 0;
}
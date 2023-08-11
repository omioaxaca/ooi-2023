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

  // Crear un arreglo de sumas acumulativas
  vector<int> sumas(cantidadNumeros);
  for (int i = 0; i < cantidadNumeros; ++i) {
    sumas[i] = numeros[i];
    if (i > 0) {
      sumas[i] += sumas[i - 1];
    }
    
    cout << sumas[i]  << " ";
  }
  cout << endl;

  // Usar el arreglo de sumas acumulativas para
  // encontrar la suma entre este rango.
  int resultado = sumas[der];
  // Restar la suma acumulativa de la izquiera solo si es mayor a 0.
  if (izq > 0) {
    resultado -= sumas[izq - 1];
  }
  cout << resultado;


  return 0;
}
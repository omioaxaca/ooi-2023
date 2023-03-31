#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>

const int INVALIDO = -1;

using namespace std;

int memo[10001];

// Regresa la minima cantidad de numeros elevados al cuadrado que al sumarse dan N.
int contarCuadrados(int n) {
  // Casos base
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  // Si ya lo hemos calculado.
  if (memo[n] != INVALIDO) {
    return memo[n];
  }

  // Probar con todos los numeros menores a la raiz cuadrada.
  int limite = sqrt(n);
  int contador = INT32_MAX;
  for (int i = 1; i <= limite; ++i) {
    contador = min(contador, contarCuadrados(n - i * i) + 1);
  }
  // Guardar en memoria.
  memo[n] = contador;
  return contador;
}

int main() {
  int casos;
  cin >> casos;
  memset(memo, INVALIDO, sizeof(memo));
  while (casos--) {
    int n;
    cin >> n;
    cout << contarCuadrados(n) << "\n";
  }

  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int tam_maximo = 100000;
const int valor_invalido = -1;

vector<int> memoria(tam_maximo, valor_invalido);

int factorial(int n) {
  // Consultar los casos base
  if (n == 0) return 0;
  if (n == 1) return 1;
  // Revisar si en algun momento ya hemos calculado este resultado.
  if (memoria[n] != valor_invalido) {
    return memoria[n];
  }
  // Ejecutar la funcion recursiva y guardar el resultado en la memoria.
  memoria[n] = factorial(n - 1) + factorial(n - 2);
  // Regresar el valor calculado.
  return memoria[n];
}

int main() {
  int n;
  cin >> n;
  cout << factorial(n) << endl;

  return 0;
}
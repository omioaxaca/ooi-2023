#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10000;

// Declarar una memoria que pueda contener todos los estados.
// Nota: La memoria guarda la respuesta al estado. En este caso
// guarda la suma maxima que se puede obtener a partir de este estado.
const int MAX_SUMA = MAX_N * 100;
int memoria[MAX_N][MAX_SUMA][2] = {0};

int elegirMaximaCantidad(int posicion, int suma, int disponible, const vector<int>& numeros) {
  // Casos base
  if (posicion >= numeros.size()) {
    // Estamos fuera del arreglo.
    return suma;
  }
  // Revisar si este estado ya fue calculado antes.
  if (memoria[posicion][suma][disponible] != 0) {
    return memoria[posicion][suma][disponible];
  }

  // Evaluar posibilidades
  //  Opcion 1: Tomar este numero
  int suma1 = 0;
  if (disponible) { // Solo podemos tomar este numero si esta disponible. Es decir, el anterior no fue tomado.
    suma1 = elegirMaximaCantidad(posicion + 1, suma + numeros[posicion], 0, numeros);
  }
  //  Opcion 2: No tomar este numero
  int suma2 = elegirMaximaCantidad(posicion + 1, suma, 1, numeros);

  // Guardar el resultado en la memoria.
  memoria[posicion][suma][disponible] = max(suma1, suma2);

  // Regresar la suma mas grande
  return memoria[posicion][suma][disponible];
}


int main() {
  int cantidadNumeros;
  cin >> cantidadNumeros;

  vector<int> numeros(cantidadNumeros);

  for (int& numero : numeros) {
    cin >> numero;
  }

  cout << elegirMaximaCantidad(0, 0, 1, numeros) << "\n" ;

}
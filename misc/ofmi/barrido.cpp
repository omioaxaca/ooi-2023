#include <iostream>
#include <vector>

using namespace std;

const int valorMaximo = 10000;

int main() {
  int cantidadNumeros;
  int k;
  cin >> cantidadNumeros >> k;

  // Leer la lista de numeros
  vector<int> numeros(cantidadNumeros);
  for (int i = 0; i < cantidadNumeros; ++i) {
    cin >> numeros[i];
  }

  // Declarar la memoria. Declarar un arreglo llamado memoria con 10000 espacios inicializados en 0.
  vector<int> memoria(valorMaximo, 0);

  // Implementar un barrido para encontrar la cantidad de parejas que suman k.
  int cantidadParejas = 0;
  for (int i = 0; i < cantidadNumeros; ++i) {
    // Buscamos una pareja x,y tal que al sumar den k.
    // Es decir: x + y = k
    // Asumimos que la posicion en la que estoy actualmente representa x.
    // Entonces tengo una sola incognita que es y. Despejamos:
    // y = k - x
    int x = numeros[i]; // 7
    int y = k - x; // 5

    // Ahora solo necesito saber cuantas veces he visitado casillas con el valor y
    // para saber la cantidad de parejas posibles.
    cantidadParejas += memoria[y];

    // Marcar a este numero, es decir a x, en la memoria.
    memoria[x]++;
  }

  cout << cantidadParejas << endl;


  return 0;
}
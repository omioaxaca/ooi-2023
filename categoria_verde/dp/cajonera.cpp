#include <iostream>
#include <cstring>

using namespace std;

typedef long long int i64;

int numCajones;  // Cantidad total de cajones
int objetivo; // Representa la cantidad de cajones seguros que buscamos

const int INVALIDO = -1;
i64 memoria[65][2][65];

i64 solve(int pos, bool prevCerrado, int cajonesSeguros) {
  // Caso base
  if (pos >= numCajones) {
    if (cajonesSeguros == objetivo) {
      return 1; // Se encontro una combinacion.
    }
    else {
      return 0;
    }
  }

  // Revisar si ya calculamos este estado antes.
  if (memoria[pos][prevCerrado][cajonesSeguros] != INVALIDO) {
    return memoria[pos][prevCerrado][cajonesSeguros];
  }

  // Evaluar las posibilidades.
  i64 contador = 0;
  // 1. Cerrar el cajon actual.
  if (prevCerrado) {
    // Al cerrar el cajon actual se vuelve seguro, ya que el anterior tambien estaba cerrado.
    contador += solve(pos + 1, true, cajonesSeguros + 1);
  }
  else {
    // Al cerrar este cajon, no se vuelve seguro porque el anterior estada abierto.
    contador += solve(pos + 1, true, cajonesSeguros);
  }
  // 2. Dejar el cajon abierto.
  contador += solve(pos + 1, false, cajonesSeguros);

  // Memorizar este estado.
  memoria[pos][prevCerrado][cajonesSeguros] = contador;
  return contador;
}

int main() {
  // Configura la memoria con valores invalidos.
  memset(memoria, INVALIDO, sizeof(memoria));

  cin >> numCajones >> objetivo;
  // En el estado inicial podemos asumir que el previo esta cerrado, ya que es la tapa superior.
  cout << solve(0, true, 0) << "\n";

  return 0;
}
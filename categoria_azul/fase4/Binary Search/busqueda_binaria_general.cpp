#include <iostream>

using namespace std;

bool cumpleCondicion(int a, int x) {
  if (a >= x) {
    return true;
  }
  else {
    return false;
  }
}

int lowerBound(int ini, int fin, int objetivo) {
  while (ini < fin) {
    int mitad = ini + (fin - ini) / 2;
    if (cumpleCondicion(mitad, objetivo)) {
      fin = mitad;
    }
    else {
      ini = mitad + 1;
    }
  }
  return ini;
}

int upperBound(int ini, int fin, int objetivo) {
  while (ini < fin) {
    int mitad = ini + (fin - ini + 1) / 2;
    if (cumpleCondicion(mitad, objetivo)) {
      ini = mitad;
    }
    else {
      fin = mitad - 1;
    }
  }
  return ini;
}

int main() {


  return 0;
}
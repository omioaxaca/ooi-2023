// https://omegaup.com/arena/problem/Trajineras/#problems
#include <iostream>
#include <vector>

using namespace std;

vector<int> robots;
vector<int> sumas;

// Devolver la suma de los valores del vector robots de un grupo que
// inicia en el indiceInicio y es de tamanio tamGrupo.
int obtenerSuma(int tamGrupo, int indiceInicio) {
  int suma = 0;
  int indiceFin = indiceInicio + tamGrupo - 1;
  for (int i = indiceInicio; i <= indiceFin; ++i) {
    suma += robots[i];
  }
  return suma;
}

// Complejidad O(1)
int obtenerSumaRapido(int tamGrupo, int indiceInicio) {
  int suma = 0;
  int indiceFin = indiceInicio + tamGrupo - 1;
  suma = sumas[indiceFin];
  if (indiceInicio > 0) {
    suma -= sumas[indiceInicio - 1];
  }
  return suma;
}

// Regresa true si es posible formar grupos de tamanio tamGrupo cuya suma sea
// menor a la carga maxima.
// Complejidad O(N)
bool esPosibleFormarGrupos(int tamGrupo, int cargaMaxima) {
  // Crear un grupo de tamanio tamGrupo para todas las posiciones del vector.
  for (int i = 0; i <= robots.size() - tamGrupo + 1; ++i) {
    int suma = obtenerSumaRapido(tamGrupo, i);
    // Comprobar si este grupo excede la carga maxima.
    if (suma > cargaMaxima) {
      return false;
    }
  }
  // si llegamos a este punto, entonces es posible formar todos los grupos con una
  // suma menor a la carga maxima.
  return true;
}

// Complejidad O(logN * N)
int busquedaBinaria(int cargaMaxima) {
  int ini = 0;
  int fin = robots.size();
  while (ini < fin) {
    int mitad = ini + (fin - ini + 1) / 2;
    int tamGrupo = mitad;
    if (esPosibleFormarGrupos(tamGrupo, cargaMaxima)) {
      // Este es un resultado valido, entonces muevo el inicio a la mitad.
      // Lo cual aun incluye este resultado, pero quiero seguir buscando uno mayor.
      ini = mitad;
    }
    else {
      // Este es un resultado invalido, entonces busco en la mitad inferior.
      fin = mitad - 1;
    }
  }
  // Al final, ini y fin valen lo mismo, regresa cualquiera de ellos.
  return ini;
}

int main() {
  int cantidadRobots;
  int cargaMaxima;

  // Leer la informacion de los pesos
  cin >> cantidadRobots >> cargaMaxima;
  robots.resize(cantidadRobots);
  for (int i = 0; i < robots.size(); ++i) {
    cin >> robots[i];
  }

  // Precalcular sumas
  sumas.resize(cantidadRobots);
  sumas[0] = robots[0];
  for (int i = 1; i < sumas.size(); ++i) {
    sumas[i] = sumas[i - 1] + robots[i];
  }

  // int maxGrupo = cantidadRobots; // Asumir que es posible formar un grupo con todos los robots.
  // // Tratar de crear grupos de tamano desde 1 hasta cantidadRobots.
  // for (int tamGrupo = 1; tamGrupo <= cantidadRobots; ++tamGrupo) {
  //   if (!esPosibleFormarGrupos(tamGrupo, cargaMaxima)) {
  //     maxGrupo = tamGrupo - 1;
  //     break;
  //   }
  // }
  int maxGrupo = busquedaBinaria(cargaMaxima);

  cout << maxGrupo << endl;

  return 0;
}
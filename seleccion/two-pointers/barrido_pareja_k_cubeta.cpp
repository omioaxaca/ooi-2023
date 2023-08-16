#include <bits/stdc++.h>

using namespace std;

// Obtener las ocurrencias de y en el pasado
// Complejidad constante O(1)
int obtenerOcurrenciasAnteriores(int y, vector<int>& ocurrencias) {
  return ocurrencias[y];
}

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

  int contador = 0;
  vector<int> ocurrencias(1001, 0);
  for (int i = 0; i < n; ++i) {
    int x = numeros[i];
    int y = k - x;
    // Buscar cuantas veces aparece Y en los numeros anteriores.
    int ocurrenciasY = obtenerOcurrenciasAnteriores(y, ocurrencias);
    // El contador de parejas incrementa de acuerdo a la cantidad
    // de ocurrencias de y que encontramos.
    contador += ocurrenciasY;

    // Registrar la ocurrencia de x
    ocurrencias[x]++;
  }

  cout << contador << "\n";

  return 0;
}
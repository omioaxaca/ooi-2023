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

  bool encontrado = false;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int suma = numeros[i] + numeros[j];
      if (suma == k) {
        encontrado = true;
        break;
      }
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

#include <iostream>
#include <string>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  string cadena;
  cin >> cadena;

  // Declarar un apuntador al inicio de la cadena.
  int izq = 0;
  // Declarar un apuntador al ultimo elemento de la cadena.
  int der = cadena.length() - 1;

  // Asumir que la palabra si es palindromo.
  bool esPalindromo = true;
  while (izq < der) {
    if (cadena[izq] == cadena[der]) {
      // Puede ser palindromo
      izq++;
      der--;
    }
    else {
      // No es palindromo.
      esPalindromo = false;
      break;
    }
  }

  // Revisar si es palindromo
  if (esPalindromo) {
    cout << "Es palindromo";
  }
  else {
    cout << "No es palindromo";
  }


  return 0;
}
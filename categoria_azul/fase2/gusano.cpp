// https://omegaup.com/arena/problem/gusano_escalador/#problems

#include <iostream>

using namespace std;

int main() {
    int altura_pozo, escala, resbala;
    cin >> altura_pozo >> escala >> resbala;

    int cantidad_escalada = 0;
    int tiempo = 0;

    while (true) {
        // Escalar
        tiempo = tiempo + 1;
        cantidad_escalada = cantidad_escalada + escala;
        // Comprobar si ya salimos
        if (cantidad_escalada >= altura_pozo) {
            break;
        }
        // Descansar y resbalarse
        tiempo = tiempo + 1;
        cantidad_escalada = cantidad_escalada - resbala;
    }

    cout << tiempo << endl;
  
    return 0 ;
}

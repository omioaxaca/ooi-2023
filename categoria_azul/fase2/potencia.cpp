// https://omegaup.com/arena/problem/potencia-ovi/#problems

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X, A, B;

    cin >> X >> A >> B;

    if ( X == 1 ) {
        cout << pow(A+3, B) << endl;
    } else {
        cout << pow(B+1, A) << endl;
    }

    return 0;
}

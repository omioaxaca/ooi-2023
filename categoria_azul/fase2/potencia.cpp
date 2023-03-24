// https://omegaup.com/arena/problem/potencia-ovi/#problems

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int X, A, B;

    cin >> X >> A >> B;

    if ( X == 1 ) {
        int ans = pow(A+3, B);
        cout << ans << endl;
    } else {
        int ans = pow(B+1, A);
        cout << ans << endl;
    }

    return 0;
}

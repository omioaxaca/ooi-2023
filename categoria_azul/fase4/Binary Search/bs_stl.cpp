// #include <iostream>
// #include <vector>
// #include <algorithm>

#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> arr) {
    for (auto elm : arr) {
        cout << elm << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = { 2, 3, 4, 10, 40 };

    print_vector(arr);

    cout << binary_search(arr.begin(), arr.end(), 2) << endl;
    cout << binary_search(arr.begin(), arr.end(), 25) << endl;

}

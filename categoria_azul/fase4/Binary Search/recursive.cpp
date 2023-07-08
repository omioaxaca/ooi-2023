#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> arr) {
    for (auto elm : arr) {
        cout << elm << " ";
    }

    cout << endl;
}

// An iterative binary search function.
bool binary_search(vector<int> arr, int l, int r, int x) {

    if (l > r)
        return false;

    int m = l + (r - l) / 2;

    // Check if x is present at mid
    if (arr[m] == x)
        return true;

    // If x greater, ignore left half
    if (arr[m] < x)
        return binary_search(arr, m+1, r, x);

    // Search in the left part
    return binary_search(arr, l, m-1, x);
}

int main() {
    vector<int> arr = { 2, 3, 4, 10, 40 };

    print_vector(arr);

    cout << binary_search(arr, 0, arr.size(), 2) << endl;
    cout << binary_search(arr, 0, arr.size(), 25) << endl;

}

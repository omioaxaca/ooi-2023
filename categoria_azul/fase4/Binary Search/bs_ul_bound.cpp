#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> arr) {
    for (auto elm : arr) {
        cout << elm << " ";
    }

    cout << endl;
}

int bs_lower_bound(vector<int> arr, int N, int X) {
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high) {
        mid = low + (high - low) / 2;

        // If X is less than or equal
        // to arr[mid], then find in
        // left subarray
        if (X <= arr[mid]) {
            high = mid;
        }

        // If X is greater arr[mid]
        // then find in right subarray
        else {
            low = mid + 1;
        }
    }

    // if X is greater than arr[n-1]
    if(low < N && arr[low] < X) {
       low++;
    }

    // Return the lower_bound index
    return low;
}

// Function to implement upper_bound
int bs_upper_bound(vector<int> arr, int N, int X) {
    int mid;

    // Initialise starting index and
    // ending index
    int low = 0;
    int high = N;

    // Till low is less than high
    while (low < high) {
        // Find the middle index
        mid = low + (high - low) / 2;

        // If X is greater than or equal
        // to arr[mid] then find
        // in right subarray
        if (X >= arr[mid]) {
            low = mid + 1;
        }

        // If X is less than arr[mid]
        // then find in left subarray
        else {
            high = mid;
        }
    }

    // if X is greater than arr[n-1]
    if(low < N && arr[low] <= X) {
       low++;
    }

    // Return the upper_bound index
    return low;
}

int main() {
    vector<int> arr = { 2, 3, 4, 4, 10 };

    print_vector(arr);

    int up = bs_upper_bound(arr, arr.size()-1, 4);
    int low = bs_lower_bound(arr, arr.size()-1, 4);

    cout << up << " " << arr[up] << endl;
    cout << low << " " << arr[low] << endl;

    up = upper_bound(arr.begin(), arr.end(), 4) - arr.begin();
    low = lower_bound(arr.begin(), arr.end(), 4) - arr.begin();

    cout << up << " " << arr[up] << endl;
    cout << low << " " << arr[low] << endl;
}

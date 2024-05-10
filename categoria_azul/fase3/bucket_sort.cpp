#include <bits/stdc++.h>

using namespace std;


int hash_function(int num, int bucket_range, int num_buckets) {
    int bucket_number = num / bucket_range;
    if ( bucket_number == num_buckets) {
        bucket_number --;
    }

    return bucket_number;
}

void bucket_sort(vector<int> &array, int num_buckets=10) {
    int minimun = *min_element(array.begin(), array.end());
    int maximun = *max_element(array.begin(), array.end());

    int range = maximun - minimun;
    int bucket_range = ceil((double) range / num_buckets);

    vector<vector<int>> buckets(num_buckets, vector<int> ());

    for (auto elm : array) {
        int index = hash_function(elm, bucket_range, num_buckets);
        buckets[index].push_back(elm);
    }

    for (auto &bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    int index = 0;
    for (auto &bucket: buckets) {
        for (auto elm : bucket) {
            array[index++] = elm;
        }
    }
}


void print_vector(vector<int> s) {
    for (auto elm : s) {
        cout << elm << " ";
    }
    cout << endl;
}

int main () {
    vector<int> array= {2, 3, 4, 1, 2, 4, 7, 33, 62, 67, 12, 76, 34, 43, 53, 16, 71};
    print_vector(array);

    bucket_sort(array);
    print_vector(array);

    return 0;
}

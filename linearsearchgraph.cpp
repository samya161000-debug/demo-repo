#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 50000};

    for (int n : sizes) {
        vector<int> arr(n);

        // Fill array with random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        int key = arr[n - 1]; // worst-case search

        auto start = high_resolution_clock::now();
        linearSearch(arr, key);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}
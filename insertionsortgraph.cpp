#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Insertion Sort Function
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 50000};

    for (int n : sizes) {
        vector<int> arr(n);

        // Fill array with random values
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        auto start = high_resolution_clock::now();
        insertionSort(arr);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}
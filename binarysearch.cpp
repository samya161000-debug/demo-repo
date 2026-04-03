#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int binarysearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return binarysearch(arr, mid + 1, high, x);
    else
        return binarysearch(arr, low, mid - 1, x);
}

int main() {
    srand(time(0));   

    int n = 10;
    int arr[n];

    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + (rand() % 5 + 1); 
    }

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = binarysearch(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

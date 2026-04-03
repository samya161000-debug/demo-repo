#include <iostream>
#include <ctime>     
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t start = clock();

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;  
            }
        }
    }
    clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "\n\nTime taken: " << time_taken << " seconds\n";

    return 0;
}

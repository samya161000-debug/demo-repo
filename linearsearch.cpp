#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i+1;  
    }
    return -1;         
}

int main()
{
    int n, key;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    srand(time(0));

    cout << "Generated array:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;   
        cout << arr[i] << " ";
    }

    cout << "Enter element to search: ";
    cin >> key;

    // Start time
    clock_t start = clock();

    int result = linearSearch(arr, n, key);

    // End time
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time taken: " << timeTaken << " seconds" << endl;

    return 0;
}
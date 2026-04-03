#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate random array
    cout << "Generated array:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;  // 0–999
        cout << arr[i] << " ";
    }

    // Start time
    clock_t start = clock();

    // Sorting
    bubbleSort(arr, n);

    // End time
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout <<timeTaken << " seconds" << endl;

    return 0;
}

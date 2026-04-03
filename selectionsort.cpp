#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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
        arr[i] = rand() % 1000;   // 0–999
        cout << arr[i] << " ";
    }

    // Start time
    clock_t start = clock();

    // Sorting
    selectionSort(arr, n);

    // End time
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nTime taken: " << timeTaken << " seconds" << endl;

    return 0;
}

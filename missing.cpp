#include <iostream>
using namespace std;

int missing(int arr[], int n, int sum)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return sum - s;
}

int main()
{
    int sum = 0;

    // sum of numbers from 1 to 10
    for (int i = 1; i <= 10; i++)
    {
        sum = sum + i;
    }

    int arr[] = {1, 2, 4, 5, 6, 7, 8, 9, 10};
    int count = sizeof(arr) / sizeof(arr[0]);

    int miss = missing(arr, count, sum);
    cout << "Missing number: " << miss << endl;

    return 0;
}

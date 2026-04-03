#include<iostream>
using namespace std;
void minmax(int arr[], int st, int end, int &min, int &max) {

    if (st == end) {
        min = arr[st];
        max= arr[st];
        return;
    }

    int mid = (st + end) / 2;

    int leftMin, leftMax;
    int rightMin, rightMax;

    minmax(arr, st, mid, leftMin, leftMax);
    minmax(arr, mid + 1, end, rightMin, rightMax);

    if (leftMin < rightMin)
        min = leftMin;
    else
        min = rightMin;

    if (leftMax > rightMax)
        max = leftMax;
    else
        max = rightMax;
}
int main() {
    int arr[] = {4, 9, 1, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minimum, maximum;

    minmax(arr, 0, n - 1, minimum, maximum);

    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}
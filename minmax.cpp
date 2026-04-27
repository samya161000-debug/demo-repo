#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mn = arr[0];
    int mx = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < mn)
            mn = arr[i];

        if (arr[i] > mx)
            mx = arr[i];
    }

    cout << "Minimum element: " << mn << endl;
    cout << "Maximum element: " << mx << endl;

    return 0;
}
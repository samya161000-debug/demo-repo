#include <iostream>
using namespace std;

int horner(int coeffs[], int n, int x) {
    int result = coeffs[0];

    for (int i = 1; i < n; i++) {
        result = result * x + coeffs[i];
    }

    return result;
}

int main() {
    int n, x;

    cout << "Enter number of coefficients: ";
    cin >> n;

    int coeffs[n];
    cout << "Enter coefficients (highest degree first): ";
    for (int i = 0; i < n; i++) {
        cin >> coeffs[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    int result = horner(coeffs, n, x);
    cout << "Result: " << result << endl;

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L = chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] 
                         + p[i-1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n-1];
}

int main() {
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p)/sizeof(p[0]);

    cout << "Minimum multiplications: "
         << matrixChainOrder(p, n);

    return 0;
}

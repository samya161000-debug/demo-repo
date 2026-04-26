#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    // Allocation Matrix
    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Max Matrix
    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    // Available Resources
    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Safety Algorithm
    bool finish[n] = {false};
    int safeSeq[n];
    int work[m];

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is NOT in safe state\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state\nSafe sequence: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";

    // -------- Request Algorithm --------
    int p;
    cout << "\n\nEnter process number making request: ";
    cin >> p;

    int req[m];
    cout << "Enter request vector:\n";
    for (int i = 0; i < m; i++)
        cin >> req[i];

    // Check request <= need
    for (int i = 0; i < m; i++) {
        if (req[i] > need[p][i]) {
            cout << "Error: Request exceeds need\n";
            return 0;
        }
    }

    // Check request <= available
    for (int i = 0; i < m; i++) {
        if (req[i] > avail[i]) {
            cout << "Resources not available\n";
            return 0;
        }
    }

    // Pretend allocation
    for (int i = 0; i < m; i++) {
        avail[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }

    cout << "Request granted (safe to allocate)\n";

    return 0;
}
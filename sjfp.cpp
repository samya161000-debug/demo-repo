#include <iostream>
using namespace std;

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], rt[n], wt[n] = {0}, tat[n];
    
    // Input burst time
    for (int i = 0; i < n; i++) {
        cout << "Enter BT for P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i]; // remaining time
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0, done;

    do {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while (!done);

    // Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Output
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
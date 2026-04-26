#include <iostream>
using namespace std;

int main() {
    int n, f;

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    int frame[f], time[f];
    int faults = 0, counter = 0;

    // Initialize
    for (int i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check hit
        for (int j = 0; j < f; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                time[j] = ++counter; // update recent use
                break;
            }
        }

        // Page fault
        if (!found) {
            int pos = 0;

            // Find least recently used
            for (int j = 1; j < f; j++) {
                if (time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            time[pos] = ++counter;
            faults++;

            cout << "Page Fault: ";
        } else {
            cout << "Hit: ";
        }

        // Display frames
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "\nTotal Page Faults = " << faults << endl;

    return 0;
}
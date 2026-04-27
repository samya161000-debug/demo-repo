#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

// Comparator: sort by finish time
bool comp(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    sort(arr.begin(), arr.end(), comp);

    int count = 1;
    int lastFinish = arr[0].finish;

    cout << "Selected activities:\n";
    cout << arr[0].start << " " << arr[0].finish << endl;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << arr[i].start << " " << arr[i].finish << endl;
            lastFinish = arr[i].finish;
            count++;
        }
    }

    cout << "Max activities: " << count << endl;

    return 0;
}
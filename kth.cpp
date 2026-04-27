#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : arr)
        pq.push(x);

    for (int i = 1; i < k; i++)
        pq.pop();

    cout << "Kth smallest: " << pq.top();

    return 0;
}
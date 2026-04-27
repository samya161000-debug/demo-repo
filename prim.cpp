#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   // number of vertices

    vector<vector<int>> cost(n, vector<int>(n));

    // adjacency matrix input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<int> visited(n, 0);
    visited[0] = 1;

    int edges = 0, minCost = 0;

    cout << "MST edges:\n";

    while (edges < n - 1) {
        int minEdge = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j]) {
                        if (cost[i][j] < minEdge) {
                            minEdge = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << minEdge << endl;

        visited[y] = 1;
        minCost += minEdge;
        edges++;
    }

    cout << "Total MST cost: " << minCost << endl;

    return 0;
}
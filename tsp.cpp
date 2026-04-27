#include <bits/stdc++.h>
using namespace std;

int n;
int dist[20][20];

int dp[20][1 << 20];

// mask → visited cities
// pos → current city

int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // return to start
    }

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            ans = min(ans,
                      dist[pos][city] +
                      tsp(city, mask | (1 << city)));
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    memset(dp, -1, sizeof(dp));

    cout << "Minimum cost of TSP: "
         << tsp(0, 1) << endl;

    return 0;
}



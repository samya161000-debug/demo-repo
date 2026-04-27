#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;   // nodes, edges

    vector<vector<pair<int,int>>> adj(n);

    // input edges: u v w
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    int src = 0; // source node

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;

            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
                parent[v] = node;
            }
        }
    }

    // Print shortest distances
    cout << "Distances from source:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> " << dist[i] << endl;
    }

    // Function to print path
    cout << "\nShortest paths:\n";
    for (int i = 0; i < n; i++) {
        cout << "Path to " << i << " : ";

        vector<int> path;
        for (int v = i; v != parent[v]; v = parent[v])
            path.push_back(v);

        path.push_back(src);

        reverse(path.begin(), path.end());

        for (int v : path)
            cout << v << " ";

        cout << endl;
    }

    return 0;
}
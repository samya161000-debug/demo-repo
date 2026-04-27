#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

// Disjoint Set Union (Union-Find)
int parent[1000], rnk[1000];

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a != b) {
        if (rnk[a] < rnk[b])
            parent[a] = b;
        else if (rnk[a] > rnk[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rnk[a]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;   // nodes, edges

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), comp);

    // DSU init
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int cost = 0;

    cout << "MST edges:\n";

    for (auto e : edges) {
        if (findParent(e.u) != findParent(e.v)) {
            unionSet(e.u, e.v);
            cost += e.w;
            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }

    cout << "Total MST cost: " << cost << endl;

    return 0;
}
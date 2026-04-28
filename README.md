# Data Structures & Algorithms Lab Repository

This repository contains implementations of fundamental algorithms from multiple lab sessions. Each lab focuses on a specific category of problems such as sorting, searching, graph algorithms, and optimization techniques.

# Basics & Recursion

* Bubble Sort
  
* Selection Sort
* Horner’s Rule
* Linear Search
* Missing Number
* Permutations
* Xⁿ (Power using recursion)
* Velocity (No tips problem)
* Tower of Hanoi
* Truth Table

## Searching & Simple Sorting

* Binary Search
* Insertion

### Efficient Sorting

* Merge Sort
* Quick Sort

## Divide & Conquer

* Kth Smallest Element
* Min-Max

## Advanced Algorithms

* Convex Hull
* Knapsack Problem
* Matrix Multiplication
* Strassen’s Matrix Multiplication

## Greedy & Graphs

* Activity Selection
* Dijkstra’s Algorithm

  #include <iostream>
using namespace std;
int main() {
int n = 5;
int graph[5][5] = {
        {0,10,0,30,100},
        {0,0,50,0,0},
        {0,0,0,0,10},
        {0,0,20,0,60},
        {0,0,0,0,0}
    };

    int dist[5];
    int visited[5];

    for(int i = 0; i < n; i++) {
        dist[i] = 999;
        visited[i] = 0;
    }

    int start = 0;
    dist[start] = 0;

    for(int count = 0; count < n-1; count++) {
        int min = 999, u;
   for(int i = 0; i < n; i++) {
            if(visited[i] == 0 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
 visited[u] = 1;

 for(int v = 0; v < n; v++) {
            if(graph[u][v] != 0 && visited[v] == 0) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
 cout << "Shortest distances from node 0:\n";
    for(int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
}
   return 0;
}

## Minimum Spanning Tree

* Kruskal’s Algorithm
  
  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    return 0;
}
* Prim’s Algorithm
  
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

## Advanced Graph Problems

* Dijkstra Path Printing
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
* Cycle Detection

  #include <iostream>
using namespace std;

int graph[5][5] = {
    {0,1,0,0,0},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {0,1,0,0,0}, 
    {0,0,0,0,0}
};

int visited[5];
int recStack[5];

bool dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < 5; i++) {
        if(graph[node][i]) {
            if(!visited[i] && dfs(i))
                return true;
            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = 0;
    return false;
}

int main() {
    for(int i = 0; i < 5; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for(int i = 0; i < 5; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                cout << "Cycle detected";
                return 0;
            }
        }
    }

    cout << "No cycle";
    return 0;
}
* Multistage Graph
  #include <iostream>
using namespace std;

int main() {
    int n = 8;

    int graph[8][8] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}
    };

    int cost[8];
    int path[8];

    cost[n-1] = 0;

    for(int i = n-2; i >= 0; i--) {
        cost[i] = 999;

        for(int j = i+1; j < n; j++) {
            if(graph[i][j] != 0) {
                if(graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

    cout << "Minimum cost: " << cost[0] << endl;

    cout << "Path: ";
    int i = 0;
    while(i != n-1) {
        cout << i << " -> ";
        i = path[i];
    }
    cout << n-1;

    return 0;
}
* Traveling Salesman Problem (TSP)
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



---

# How to Run Programs

1. Compile the code:

```bash
g++ filename.cpp -o output
```

2. Run:

```bash
./output
```

---

# Important Complexities

| Algorithm         | Time Complexity    |
| ----------------- | ------------------ |
| Bubble Sort       | O(n²)              |
| Selection Sort    | O(n²)              |
| Insertion Sort    | O(n²)              |
| Merge Sort        | O(n log n)         |
| Quick Sort        | O(n log n) avg     |
| Binary Search     | O(log n)           |
| Dijkstra          | O(V²) / O(E log V) |
| Kruskal           | O(E log E)         |
| Prim              | O(E log V)         |
| Knapsack (DP)     | O(nW)              |
| TSP (Brute Force) | O(n!)              |

---

# Concepts Covered

* Sorting Algorithms
* Searching Techniques
* Divide and Conquer
* Greedy Algorithms
* Dynamic Programming
* Graph Algorithms
* Recursion & Backtracking

---

# 🔍 Algorithm Explanations

## Bubble Sort

Compares adjacent elements and swaps them if needed. Largest elements move to the end after each pass.

## Selection Sort

Selects the smallest element and places it at the correct position.

## Horner’s Rule

Efficient polynomial evaluation by reducing repeated multiplications.

## Linear Search

Checks each element sequentially until the target is found.

## Missing Number

Finds missing value using sum formula or XOR technique.

## Permutations

Generates all possible arrangements using recursion and swapping.

## Xⁿ (Power)

Uses recursion or fast exponentiation (divide & conquer).

## Velocity (No Tips Problem)

Applies formula-based logic to compute motion-related values.

## Tower of Hanoi

Recursive solution:
move n-1 disks → move largest → move n-1 again.

## Truth Table

Shows all logical input-output combinations.

## Binary Search

Divides sorted array repeatedly to find target efficiently.

## Insertion Sort

Builds sorted list by inserting elements at correct position.

## Merge Sort

Divides array, sorts recursively, then merges.

## Quick Sort

Partitions around pivot and sorts recursively.

## Kth Smallest Element

Finds kth smallest using sorting or QuickSelect.

## Min-Max

Uses divide & conquer to reduce comparisons.

## Convex Hull

Finds smallest boundary enclosing all points.

## Knapsack Problem

Maximizes value under weight constraint (DP/greedy).

## Matrix Multiplication

Row × column multiplication of matrices.

## Strassen’s Algorithm

Optimized matrix multiplication using divide & conquer.

## Activity Selection

Greedy method selecting max non-overlapping activities.

## Dijkstra’s Algorithm

Finds shortest path from source to all nodes.

## Kruskal’s Algorithm

Builds MST using smallest edges without cycles.

## Prim’s Algorithm

Builds MST by expanding from a starting node.

## Dijkstra Path Printing

Stores parent array to reconstruct shortest path.

## Cycle Detection

Detects cycles using DFS or Union-Find.

## Multistage Graph

Solves shortest path stage-by-stage using DP.

## Traveling Salesman Problem (TSP)

Finds minimum cost path visiting all nodes once.

---

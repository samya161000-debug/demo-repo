# Data Structures & Algorithms Lab Repository

This repository contains implementations of fundamental algorithms from multiple lab sessions. Each lab focuses on a specific category of problems such as sorting, searching, graph algorithms, and optimization techniques.

# Basics & Recursion

* Bubble Sort
  #include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate random array
    cout << "Generated array:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;  // 0–999
        cout << arr[i] << " ";
    }

    // Start time
    clock_t start = clock();

    // Sorting
    bubbleSort(arr, n);

    // End time
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout <<timeTaken << " seconds" << endl;

    return 0;
}
* Selection Sort

 #include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // Seed random number generator
    srand(time(0));

    // Generate random array
    cout << "Generated array:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;   // 0–999
        cout << arr[i] << " ";
    }

    // Start time
    clock_t start = clock();

    // Sorting
    selectionSort(arr, n);

    // End time
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nTime taken: " << timeTaken << " seconds" << endl;

    return 0;
}
* Horner’s Rule
  #include <iostream>
using namespace std;

int horner(int coeffs[], int n, int x) {
    int result = coeffs[0];

    for (int i = 1; i < n; i++) {
        result = result * x + coeffs[i];
    }

    return result;
}

int main() {
    int n, x;

    cout << "Enter number of coefficients: ";
    cin >> n;

    int coeffs[n];
    cout << "Enter coefficients (highest degree first): ";
    for (int i = 0; i < n; i++) {
        cin >> coeffs[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    int result = horner(coeffs, n, x);
    cout << "Result: " << result << endl;

    return 0;
}
* Linear Search
  #include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 50000};

    for (int n : sizes) {
        vector<int> arr(n);

        // Fill array with random numbers
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        int key = arr[n - 1]; // worst-case search

        auto start = high_resolution_clock::now();
        linearSearch(arr, key);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << n << "\t" << duration.count() << endl;
    }

    return 0;
}
* Missing Number
* Permutations
  #include <iostream>
#include <string>
using namespace std;
void permute(string str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {
       
       swap(str[l], str[i]);
       permute(str, l + 1, r);

       
        swap(str[l], str[i]);
    }
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    permute(s, 0, s.length() - 1);

    return 0;
}
* Xⁿ (Power using recursion)
* Velocity (No tips problem)
  #include<iostream>
using namespace std;
int velocity(int u,int a ,int t){
    int v=u+(a*t);
    return v;
}
int main(){
    int u,a,t;
    cout<<"Enter initial velocity, acceleration and time:"<<endl;
    cin>>u>>a>>t;
    cout<<"Final velocity is: "<<velocity(u,a,t)<<endl;
}
* Tower of Hanoi
  #include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}


## Searching & Simple Sorting

* Binary Search
  #include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int binarysearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return binarysearch(arr, mid + 1, high, x);
    else
        return binarysearch(arr, low, mid - 1, x);
}

int main() {
    srand(time(0));   

    int n = 10;
    int arr[n];

    arr[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + (rand() % 5 + 1); 
    }

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Enter element to search: ";
    cin >> x;

    int result = binarysearch(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
* Insertion
  #include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

### Efficient Sorting

* Merge Sort
  #include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int st,int end,int mid){
vector<int>temp;
int i=st,j=mid+1;
while(i<=mid && j<=end){
    if(arr[i]<=arr[j]){
        temp.push_back(arr[i]);
        i++;
    }else{
        temp.push_back(arr[j]);
        j++;
    }
}
while(i<=mid){
    temp.push_back(arr[i]);
    i++;
}
while(j<=end){
    temp.push_back(arr[j]);
    j++;
}
for(int i=0;i<temp.size();i++){
    arr[st+i]=temp[i];

}
}
void mergesort(int arr[],int st,int end){
    int mid=st+(end-st)/2;
    if(st<end){
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,end);
        merge(arr,st,end,mid);
    }
}
int main(){
    int size;
    cout<<"Enter size:"<<endl;
    cin>>size;
    cout<<"enter elements"<<endl;
    int arr[100];
    for(int x=0;x<size;x++){
        cin>>arr[x];

        
    }
}
* Quick Sort
  
#include<iostream>
using namespace std;
void swap(int &a ,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void print(int arr[],int st,int end){
    for(int b=st;b<end;b++){
        cout<<arr[b]<<endl;
    }
}
int partition(int arr[], int st, int end){
    int pividx,idx;
    pividx=end;
    idx=st;
    for(int i=st;i<end;i++){
        if(arr[i]<arr[pividx]){
            swap(arr[idx],arr[i]);
            idx++;
        }
    }
    swap(arr[idx],arr[pividx]);
    return idx;
}
void quicksort(int arr[],int st,int end){
    if(st<end){
       int pividx=partition(arr,st,end);
       quicksort(arr,st,pividx-1);
       quicksort(arr,pividx+1,end);
    }
   
}
int main(){
    int size;
    cout<<"Enter size:"<<endl;
    cin>>size;
   cout<<"Enter elements"<<endl;
   int arr[100];
   for(int x=0;x<size;x++){
    cin>>arr[x];
   }
   quicksort(arr,0,size-1);
   print(arr, 0, size);
}
## Divide & Conquer

* Kth Smallest Element
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
* Min-Max
  #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mn = arr[0];
    int mx = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < mn)
            mn = arr[i];

        if (arr[i] > mx)
            mx = arr[i];
    }

    cout << "Minimum element: " << mn << endl;
    cout << "Maximum element: " << mx << endl;

    return 0;
}

## Advanced Algorithms

* Convex Hull
  #include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Global reference point
Point p0;

// Function to find orientation
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;       // collinear
    return (val > 0) ? 1 : 2;     // 1 = clockwise, 2 = counterclockwise
}

// Distance squared
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Comparator for sorting
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);

    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);

    return (o == 2);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();

    // Step 1: Find bottom-most point
    int ymin = points[0].y, min_i = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) ||
           (points[i].y == ymin && points[i].x < points[min_i].x)) {
            ymin = points[i].y;
            min_i = i;
        }
    }

    swap(points[0], points[min_i]);
    p0 = points[0];

    // Step 2: Sort by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Build hull using stack
    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (st.size() > 1) {
            Point top = st.top(); st.pop();
            Point nextToTop = st.top();

            if (orientation(nextToTop, top, points[i]) != 2)
                continue;
            else {
                st.push(top);
                break;
            }
        }
        st.push(points[i]);
    }

    // Store result
    vector<Point> hull;
    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }

    return hull;
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0},
        {3, 3}
    };

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull points:\n";
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
* Knapsack Problem
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
* Matrix Multiplication
  #include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    // cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L = chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] 
                         + p[i-1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n-1];
}

int main() {
    int p[] = {10, 30, 5, 60};
    int n = sizeof(p)/sizeof(p[0]);

    cout << "Minimum multiplications: "
         << matrixChainOrder(p, n);

    return 0;
}
* Strassen’s Matrix Multiplication
#include <bits/stdc++.h>
using namespace std;

// Add two matrices
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

// Subtract two matrices
vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

// Strassen algorithm
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();

    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    // Split matrices
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // 7 multiplications
    auto M1 = strassen(add(A11, A22), add(B11, B22));
    auto M2 = strassen(add(A21, A22), B11);
    auto M3 = strassen(A11, subtract(B12, B22));
    auto M4 = strassen(A22, subtract(B21, B11));
    auto M5 = strassen(add(A11, A12), B22);
    auto M6 = strassen(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Combine results
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + mid] = M3[i][j] + M5[i][j];
            C[i + mid][j] = M2[i][j] + M4[i][j];
            C[i + mid][j + mid] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

// Print matrix
void print(vector<vector<int>> C) {
    for (auto row : C) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> C = strassen(A, B);

    cout << "Result:\n";
    print(C);

    return 0;
}
## Greedy & Graphs

* Activity Selection
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

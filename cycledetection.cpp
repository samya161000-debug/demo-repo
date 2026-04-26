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
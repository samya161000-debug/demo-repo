#include<iostream>
using namespace std;

int tsp[10][10]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
int visited[10],n,cost =0;
void ts(int c){
int k,adj_vertex=999;
int min=999;
visited[c]=1;
cout<<c+1<<" ";
}



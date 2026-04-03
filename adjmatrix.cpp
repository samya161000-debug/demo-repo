#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    int arr[100][100];


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }


    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }


    cout<<"adjacency matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    queue<int> q;
    bool visited[100]={false};

    q.push(0);
    visited[0]=true;

    int stages=0;

    while(!q.empty()){
        int s = q.size(); 
        stages++;

        for(int i=0;i<s;i++){
            int node=q.front();
            q.pop();

            for(int j=0;j<n;j++){
                if(arr[node][j]==1 && !visited[j]){
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }

    cout<<"Number of stages = "<<stages;

    return 0;
}
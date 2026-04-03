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
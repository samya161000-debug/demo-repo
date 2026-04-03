#include<iostream>
using namespace std;

int main(){
    cout<<"Enter number of processes:"<<endl;
    int n, at[100], bt[100];
    cin>>n;

    for(int i=1;i<=n;i++){
        cout<<"Enter arrival time and burst time"<<endl;
        cout<<"arrival time:";
        cin>>at[i];
        cout<<"burst time:";
        cin>>bt[i];
    }

    int ct[100], tat[100], wt[100];


    ct[1] = at[1] + bt[1];
    tat[1] = ct[1] - at[1];
    wt[1] = tat[1] - bt[1];

    cout<<"\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    cout<<"P1\t"<<at[1]<<"\t"<<bt[1]<<"\t"<<ct[1]<<"\t"<<tat[1]<<"\t"<<wt[1]<<endl;


    for(int i=2;i<=n;i++){
        ct[i] = max(at[i], ct[i-1]) + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cout<<"P"<<i<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }

    float twt=0, ttt=0;

    for(int i=1;i<=n;i++){
        twt += wt[i];
        ttt += tat[i];
    }

    cout<<"Avg Waiting Time: "<<twt/n;
    cout<<"Avg Turnaround Time: "<<ttt/n;

    return 0;
}
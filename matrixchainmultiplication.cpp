#include<iostream>
using namespace std;

int main(){
    int alloc[5][3]={(0,1,0),(2,0,0),(3,0,2),(2,1,1),(0,0,2)};
    int max[5][3]={(7,5,3),(3,2,2),(9,0,2),(4,2,2),(5,3,3)};
    int need[5][3];
    int avail[3]={3,2,2};
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            need[i][j]=max[i][j]-avail[i][j];
        }
    }
    int finish[3]={0,0,0};
    int count=0;
    for(int k=0;k<5;k++){
        for(int i=0;i<3;i++){
            if(finish[i]=0){
                int ok=1;
                break;
            }
        }
    }
}
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
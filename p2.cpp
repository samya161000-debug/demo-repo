#include<iostream>
#include<unordered_map>
using namespace std;
 int partition(int arr[], int st, int end){
    int idx=st-1;
    int pivot=end;
    for(int i=st;i<end;i++){
        if(arr[i]<arr[pivot]){
          idx++;
          swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[pivot]);
    return idx;
 }
 void quicksort(int arr[],int st, int end){
    
    if(st<end){
        int pivIdx=partition( arr, st, end);
        quicksort( arr,  st,pivIdx-1);//left
        quicksort( arr, pivIdx+1, end);//right
      
    }
}

 int main(){
    int k=1,n=5;
    int arr[]={1,1,2,41,1};
    quicksort(arr,0,n-1);
   /* int count=1;
for(int i=1;i<n;i++){
    if(arr[i]==arr[i-1]){
        count++;
    }else{
       
        cout<<arr[i-1]<<"-"<<count<<endl;
        count=1;
    }
}
cout<<arr[n-1]<<"-"<<count<<endl;*/
unordered_map<int,int>freq;
for(int i=0;i<n;i++){
    freq[arr[i]]++;
}
unordered_map<int,int>::iterator it;
for( it=freq.begin();it!=freq.end();it++){
    cout<<it->first<<"-"<<it->second<<endl;
}
 }
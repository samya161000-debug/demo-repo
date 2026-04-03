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
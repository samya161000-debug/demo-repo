#include<iostream>
#include<vector>
using namespace std;
void square(int arr[], int st, int end){
    vector<int> a;
    vector<int> b;
    int l=st;
    if(arr[l]<0){
    a.push_back(arr[l]);
    l++;
    }else{
        b.push_back(arr[l]);
        l++;
    }
    int i=0,j=0,k=st;
    while(i<a.size() && j<b.size()){
        if(a[i]*a[i]<b[j]*b[j]{
            arr[k]=arr[i];
            k++;
            i++;
        }else{
            arr[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<a.size()){
        arr[k]=a[i];
        k++;
        i++;

    }
    while(j<b.size()){
        arr[k]=b[j];
        k++;
        j++;
    }
    cout<<"array"<<endl;
    for(int i=st;i<end;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int size;
    cout<<"enter size:"<<endl;
    cin>>size;
    cout<<"enter elements:"<<endl;
    int arr[100];
    for(int x=0;x<size;x++){
        cin>>arr[x];

    }
    square(arr,0,size);
}
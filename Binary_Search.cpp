#include<iostream>
using namespace std;

void print(int arr[], int s, int e){
    for (int i=s; i<=e; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool binarySearch(int *arr, int s, int e, int k ){
    print(arr,s,e);
    //base case

    //element not found
    if (s>e){
        return -1;
    }

    int mid = s + (e-s)/2;
    cout<<"Value of mid is "<<arr[mid]<<endl;

    //element found
    if(arr[mid]==k){
        return true;
    }

    if(arr[mid]<k){
        return binarySearch(arr, mid+1 , e , k);
    }
    else{
        return binarySearch(arr, s , mid-1 , k);
    }
}

int main(){
    int arr[11] = {2,4,6,8,14,16,18,22,245, 246, 267};
    int size= 11;
    int key = 22;

    cout<<"Present or not "<<binarySearch(arr, 0, 11, key)<<endl;

    return 0;
}
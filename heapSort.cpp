#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    //constructor
    heap(){
        arr[0] = -1;
        size = 0;
    } 
};
void heapify(int arr[], int n, int i ){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <=n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n ,largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    
    while(size>1){
        //step 1: swap
        swap(arr[size], arr[1]);
        size--;

        //step 2
        heapify(arr,size,1);
    }
}

int main(){
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    heapSort(arr,n);
    cout<<"printing sorted array now "<<endl;
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

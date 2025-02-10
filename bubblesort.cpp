#include<iostream>
using namespace std;

void sortarray(int *arr, int n){
  //base case - already sorted
  if(n==0 || n==1){
    return ;
  }

  //case 1 solved- putting largest element at the end
  for (int i = 0; i<n-1; i++){
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
  }

  //Recursion Call
  sortarray(arr, n-1);
}

int main(){
    int arr[5] = {5,4,2,3,1};
    sortarray(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
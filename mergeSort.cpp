#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s+ (e-s)/2;

    int length1 = mid - s + 1;
    int length2 = e - mid;

    // Create temp vectors
    int *first = new int[length1];
    int *second = new int[length2];

    //copy data to temp vectors 
    int mainarrayindex  = s; 
    for(int i =0; i<length1 ; i++){
        first[i] = arr[mainarrayindex++];
    }
     mainarrayindex  = mid+1;
    for(int i =0; i<length2 ; i++){
        second[i] = arr[mainarrayindex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;
    //merge the temp vectors back
    while(index1 < length1 && index2 < length2){
        if(first[index1] < second[index2]){
            arr[mainarrayindex++] = first[index1++];
        }
        else{
            arr[mainarrayindex++] = second[index2++];
        }
    }
     //copy the remaining elements of length1 & length2 
    while(index1 < length1){
        arr[mainarrayindex++] = first[index1++];
    }
     while(index2 < length2){
        arr[mainarrayindex++] = second[index2++];
    }

  delete []first;    //to free memory 
  delete []second;   //to free memory 
}

void mergeSort(int *arr, int s, int e){

    //base case
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    //left part sort
    mergeSort(arr, s, mid);
    //right part sort
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr,s,e);
}

int  main(){
    int arr[5]= { 3, 9, 2, 8, 5};
    int n = 5;
     
     mergeSort(arr, 0 , n-1);

     for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
     }
     return 0;
}
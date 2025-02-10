#include<iostream>
using namespace std;

int firstOccr(int arr[], int n , int key){         //n = size
    int s = 0, e = n-1;                            //s = start, e = end
    int mid = s + (e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
        ans = mid;
        e = mid- 1;
        }
        else if(arr[mid]< key){                  // go to right
         s = mid + 1;
        }
        else if(arr[mid]>key){                  // go to left
         e = mid - 1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}
int lastOccr(int arr[], int n , int key){         //n = size
    int s = 0, e = n-1;                            //s = start, e = end
    int mid = s + (e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
        ans = mid;
        s = mid + 1;
        }
        else if(arr[mid]< key){                  // go to right
         s = mid + 1;
        }
        else if(arr[mid]>key){                  // go to left
         e = mid - 1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}


int main(){

    int even[5]= {1,2,3,3,5}; 
    cout<< "First Occurance of 3 is at index  "<< firstOccr(even ,5, 3)<<endl;
    cout<< "Last Occurance of 3 is at index  "<< lastOccr(even, 5, 3)<<endl;
    return 0;
}
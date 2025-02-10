#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int mid = start+ (end-start)/2;
    while (start <= end){
        if (arr[mid] == key){
            return mid;
        }
        if (key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid= start+ (end-start)/2;
    }
}

int main(){
    int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[5] = {3, 5, 7, 9, 11};
    int key;
    int evenindex = binarySearch(even, 6, 4);
     int oddindex = binarySearch(odd, 5, 9);

    cout << "Index of "<< key <<" is " << evenindex << endl;
    cout << "Index of "<< key <<" is " << oddindex << endl;

    return 0;
}
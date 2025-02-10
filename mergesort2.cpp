#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    vector<int> temp;  // Using vector for dynamic sizing
    int left = s;
    int right = mid + 1;

    while (left <= mid && right <= e) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= e) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy temp array back to arr
    for (int i = 0; i < temp.size(); i++) {
        arr[s + i] = temp[i];
    }
}

void mergesort(int *arr, int s, int e) {
    // base case
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);  // left part sort
    mergesort(arr, mid + 1, e);  // right part sort
    merge(arr, s, e);  // merging both parts
} 

int main() {
    int arr[5] = {3, 5, 7, 2, 9};
    int n = 5;
    mergesort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

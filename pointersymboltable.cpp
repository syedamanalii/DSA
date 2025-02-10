#include<iostream>
using namespace std;

int main(){
    int arr[10] = {2,8,4,5,7};
    // arr = arr + 1 -> ERROR- Non Assignable 
    
    int *ptr = &arr[0];
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    ptr = ptr + 1;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
}
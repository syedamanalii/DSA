#include<iostream>
using namespace std;

int main(){
    int arr[5]= {1,2,3,4,5};
    char ch[6]=  "abcde";

    cout<<arr<<endl; // prints address of arr
    cout<<ch<<endl;  // prints the entire string  in ch 

    char *c = &ch[0];
    cout<<c<<endl;

    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;
    return 0;
}
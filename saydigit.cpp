#include<iostream>
using namespace std;
 
void sayDigit(int n, string arr[]){
    //base case
    if(n==0)
    return ;
    //processing
    int digit = n%10;
    n=n/10;
   // cout<<arr[digit]<<" ";   -> i/p-412   o/p-two one four

    //recursive call
    sayDigit(n, arr);
    cout<<arr[digit]<<" ";    // -> i/p-412  o/p-four one two
}

int main(){
    string arr[10]= {"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin>>n;

    cout<<endl;
    sayDigit(n,arr);
    cout<<endl;

    return 0;
}
#include<iostream>
using namespace std;

int factorial(int n){
    //base case
    if(n==0){
        return 1;
    }
   // int smallprob = factorial(n-1);
   // int bigprob = n * smallprob;
   // return bigprob;
   return n * factorial(n-1);
}
 
 int main(){
    int n;
    cin>>n;
    int ans = factorial(n);
    cout<<ans<<endl;
    return 0;
 }
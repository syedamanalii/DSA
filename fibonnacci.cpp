#include<iostream>
using namespace std;

class Solution{
    public:
    int fib(int n){
        //base case
        if(n==0)
        return 0;
        if(n==1)
        return 1;

        int ans= fib(n-1) + fib(n-2);
        return ans;
    }
};

int main(){
    Solution solution;
    int n;
    cout<<"Enter a number to caluclate its Fibonacci: ";
    cin>>n;

     int result = solution.fib(n); //call fib method
     cout<<"Fibonacci of "<<n<<" is "<<result<<endl; //output the result
    return 0;
}
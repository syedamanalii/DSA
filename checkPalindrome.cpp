#include<iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j){
    //base case
    if(i>j)
        return true;
    
    if(str[i] != str[j]){
    return false;
    }
    else{
        //Recursion call
        return checkPalindrome(str, i+1, j-1 );
    }
}

int main(){
   string name = "abbccbba";
   cout<<endl;

   bool isPalindrome = checkPalindrome(name, 0 , name.length()-1);
   if(isPalindrome){
    cout<<" It is Palindrome"<<endl;
   }
   else{
     cout<<" It is not Palindrome"<<endl;
   }
return 0;
}
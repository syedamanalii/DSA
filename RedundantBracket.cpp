#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBracket(string &s){
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        char ch = s[i];

        if(ch== '(' ||ch=='+' ||ch=='-' ||ch=='*'||ch=='/'){
            st.push(ch);
        }
        else{
            //ch can be either ') closing bracket or lowercase letter
            if(ch== ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top  = st.top();
                    if(top=='+' ||top=='-' ||top=='*'||top=='/'){
                      isRedundant = false;
                    } 
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();    //removing opening bracket
            }
        }
    }
    return false;
}

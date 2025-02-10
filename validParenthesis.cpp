#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++){

        char ch = expression[i];

        // if opening bracket, push in stack
        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        // if closing bracket, stacktop check and pop
        else{
            if(!s.empty()) {
                  char top = s.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      s.pop();
                  }
                else{
                    return false;
                }
            }
        }
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
}

int main()
{

    return 0;
}
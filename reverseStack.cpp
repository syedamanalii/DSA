#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int x) {
    // base case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    // recursive call
    solve(s, x);
    
    s.push(num);
}

void insertAtBottom(stack<int> & stack, int element) {
    // base case
    if(stack.empty()) {
        stack.push(element);
        return;
    } 
    int num = stack.top();
    stack.pop();

    // recursive call
    insertAtBottom(stack, element);
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main() {
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    
    cout << "Stack before reversing: ";
    stack<int> temp = myStack;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(myStack);

    cout << "Stack after reversing: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
 
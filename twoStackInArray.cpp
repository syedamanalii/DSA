#include <iostream>
using namespace std;

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize two stacks
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1
    void push1(int num) {
        if (top2 - top1 > 1) { // At least one empty space present
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Push in stack 2
    void push2(int num) {
        if (top2 - top1 > 1) { // At least one empty space present
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop from stack 1 and return popped element
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1; // Indicates stack underflow
        }
    }

    // Pop from stack 2 and return popped element
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1; // Indicates stack underflow
        }
    }

    // Destructor to free allocated memory
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(5);
    
    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);
    ts.push1(25);

    cout << "Popped from stack 1: " << ts.pop1() << endl; // Should print 25
    cout << "Popped from stack 2: " << ts.pop2() << endl; // Should print 20

    ts.push2(30);

    cout << "Popped from stack 1: " << ts.pop1() << endl; // Should print 15
    cout << "Popped from stack 2: " << ts.pop2() << endl; // Should print 30

    return 0;
}

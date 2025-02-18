#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public: 
    int * arr;
    int top;
    int size;

    //behavior or Constructor
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    
    void push(int element){
        if(size - top >1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
      if(top>=0){
            top--;
      }
      else{
        cout<<"Stack Underflow"<<endl;
      }
    }

    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top ==-1){
            return true;
        }
        else{
            return false;
        }
         
    }
};
int main(){
    Stack st(5);  //five spaces maximum, exceeding this means stack overflow
    
    st.push(22);
    st.push(43);
    st.push(54);
    cout<< st.peek()<<endl;
    
    st.pop();
    cout<< st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty()){
        cout<<"Stack is Empty lil bro"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    st.push(65); 
    cout<<st.peek()<<endl;

    return 0;
}
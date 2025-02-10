#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class SpecialStack{
    //define data members
    stack<int> s;
    int mini = INT_MAX;
    int mini;
    public:
    void push(int data){
        //for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data<mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr>mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMini;
        }
    }
    int top(){
        if(s.empty())
           return -1;
        
        int curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return s.empty();
        }
    }
    bool isEmpty(){
        return s.empty();
    }
    int getMini(){
        if(s.empty())
          return -1;
        return mini;
    }

};
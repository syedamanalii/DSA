#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class NStack{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;

    public:
  //initialize the data structure
    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //top initialize
        for(int i=0; i<n;i++){
            top[i] = -1;
        }
        //next initialize
        for(int i=0; i<s;i++){
            next[i] = i+1;
        }

        //updpate last index value to -1
        next[s-1] = -1;

        //initialize freespot
        freespot = 0;

    }

  //Pushes 'X' into the Mth stack, return true if it gets pushed
    bool push(int x, int m){
        if(freespot == -1){
            return false;   //check overflow condition
        }
        //find index
        int index = freespot;
        //update freespot;
        freespot = next[index];
        //insert element into array
        arr[index] = x;
        //update next
        next[index] = top[m-1];
        //update top
        top[m-1] = index;

        return true;
    }

  //Pops top element from Mth stack, return -1 if the stack is empty
    int pop(int m){
        if(top[m-1] == -1){
            return false;   //check underflow condition
        }
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;         

        return arr[index];    
    }
};
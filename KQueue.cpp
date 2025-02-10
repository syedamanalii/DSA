#include<iostream>
using namespace std;

class kQueue{
    private: 
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;
    public:
    kQueue(int n, int k){
        this-> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[n];
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }
    void enqueue(int data, int qn){
        //check overflow
        if(freeSpot == -1){
            cout<<"queue overflow"<<endl;
            return;
        }
        //find first free index
        int index = freeSpot;
        //update freeSpot
        freeSpot = next[index];
        //check whether first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            //link new element to the prev element
            next[rear[qn-1]] = index;
        }
        //update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;

        //push element
        arr[index] = data;
    }
    int dequeue(int qn){
        //underflow
        if(front[qn-1]== -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        //find index to pop
        int index = front[qn-1];
        //front to be moved ahead
        front[qn-1] = next[index];
        //freeSpot to be managed
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};
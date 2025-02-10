#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k){
    //step 1 -> pop first k from Q and put into stack
    stack<int> s;
    for(int i =0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //step 2 -> fetch from stack and push to q
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    //step 3-> fetch first (n-k) element from Q to push back
    int t = q.size() - k;    //n-k
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
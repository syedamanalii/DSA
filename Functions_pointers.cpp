#include<iostream>
using namespace std;

void print(int *p){
  cout<<*p<<endl;
}

void update(int *p){
    // p = p + 1;
    // cout<<"Inside" <<p<<endl;
    *p  = *p + 1;
}

int main(){
    int value = 5;
    int *p = &value;
   // cout<<"Before "<<p<<endl; 
   // update(p);
   // cout<<"After "<<p<<endl; 

    cout<<"Before "<<*p<<endl; 
    update(p);
    cout<<"After "<<*p<<endl; 
    return 0;
}
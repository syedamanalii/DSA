#include<iostream>
using namespace std;

void update(int **p){
  //p = p + 1;  //no change
  // *p = *p + 1;  // yes change
  **p = **p + 1; 
}

int main(){
   int i = 5;
   int *ptr = &i;
   int **ptr2 = &ptr;

   cout<<"before "<<i<<endl;
   cout<<"before "<<ptr<<endl;
   cout<<"before "<<ptr2<<endl;
   update(ptr2);
   cout<<endl;
   cout<<"after "<<i<<endl;
   cout<<"after "<<ptr<<endl;
   cout<<"after "<<ptr2<<endl;
}
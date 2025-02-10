#include<iostream>
using namespace std;

int main(){
  int arr[10] = {2,4,7,9,3};
  cout<<"Value of first memory block is "<<arr[0]<<endl;  //value at zero index
  cout<<"Address of first memory block is "<<arr<<endl; //address of the zero index
  cout<<"Address of first memory block is "<<&arr[0]<<endl; //also the address of the zero index
  cout<<"Address of second memory block is "<<&arr[1]<<endl;
  cout<<"Value of first memory block using pointer is "<<*arr<<endl;  //value at zero index

  cout<<"Increamenting the value stored in the first address "<<*arr + 1<<endl;     //value + 1 
  cout<<"increamenting the address "<<*(arr + 2)<<endl;    //block + 2 

  int i = 3;
  cout<<"using i[arr]=*(i+arr) "<<i[arr]<<endl<<endl;

  return 0;
}
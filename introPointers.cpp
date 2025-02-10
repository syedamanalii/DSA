#include<iostream>
using namespace std;

int main(){
    int num = 5;
    cout<<num<<endl;
    //address of Operator - &
    cout<< "Address of num is "<<&num<<endl;
    cout<< "Value of num is "<<num<<endl;

    int *ptr = &num;
     cout<< "Address of num using ptr is "<<ptr<<endl;
      cout<< "Value of num using ptr is "<<*ptr<<endl;

      cout<<"Size of integer is "<<sizeof(num)<<endl;
      cout<<"Size of pointer is "<<sizeof(ptr)<<endl;

    return 0;
}
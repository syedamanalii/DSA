#include<iostream>
using namespace std;

int main(){
    int i = 5;
    int*ptr = &i;
    int **ptr2 = &ptr;
    int ***ptr3 = &ptr2;

    cout<<"Value stored in i "<<i<<endl;
    cout<<"Address of i "<<&i<<endl;
    cout<<endl;
    cout<<"Value stored in i "<<*ptr<<endl;
    cout<<"Address of i "<<ptr<<endl;
    cout<<"Address of pointer 1 "<<&ptr<<endl;
    cout<<endl;
    cout<<"Value stored in i "<<**ptr2<<endl;
    cout<<"Address of i "<<*ptr2<<endl;
    cout<<"Address of pointer 1 "<<ptr2<<endl;
    cout<<"Address of pointer 2 "<<&ptr2<<endl;
    cout<<endl;
    cout<<"Value stored in i "<<***ptr3<<endl;
    cout<<"Address of i "<<**ptr3<<endl;
    cout<<"Address of pointer 1 "<<*ptr3<<endl;
    cout<<"Address of pointer 2 "<<ptr3<<endl;
    cout<<"Address of pointer 3 "<<&ptr3<<endl;
}
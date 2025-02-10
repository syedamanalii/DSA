#include<iostream>
using namespace std;

int main(){
    //create 2d array
    int arr[4][3];

    //taking input-> row wise input1
    for( int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[j][i];
        }
    }

    //print
      for( int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}
#include<iostream>
using namespace std;

void reachHome(int start, int dest){
    cout<<"source "<<start<<" destination "<<dest<<endl;
    //base case
    if(start==dest){
        cout<<"arrived"<<endl;
        return ;
    }
    //processing
    start++;

    //recursive call
    reachHome(start, dest);
}

int main(){
int dest = 10;
int start = 1;
cout<<endl;
reachHome(start,dest);
return 0;
}
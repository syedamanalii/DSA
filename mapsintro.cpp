#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //Creation
    unordered_map<string, int> m;

    //Insertion
    //method 1:
    pair<string,int> p = make_pair("aman", 3);
    m.insert(p);

    //method 2:
    pair<string, int> pair2("ali", 2);
    m.insert(pair2);

    //method 3:
    m["me"] = 1;  //creation of entry
    //what will happen if
    m["me"] = 2;  //updation of entry

    //Searching
    cout<< m["me"]<<endl;
    cout<< m.at("aman")<<endl;
 // cout<< m.at("UnknownKey")<<endl;   //Output-> std::out_of_range' what():  unordered_map::at
 // cout<< m["UnknownKey"]<<endl;      //Output -> 0
     
    //Size
    cout<<m.size()<<endl; 

    //To check Present
    cout<<m.count("bro")<<endl;  //if absent-> returns 0, if present-> returns 1

    //Erase
    m.erase("me");
    cout<<m.size()<<endl;

    //Iteration
    unordered_map<string,int> :: iterator it = m.begin();

    while( it!= m.end()){  
        cout<<it->first<<" "<<it->second<<endl;   //random order of printing but TC->O(1), using only maps follows order but TC->O(logn)
        it++;
    }

    return 0;
}
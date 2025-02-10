#include<iostream>
using namespace std;

class Node { 
    public: 
    int data; 
    Node* next; 
    Node(int d){ 
     data = d; 
     next = NULL; 
    }
};
    Node* solve(Node* first, Node* second){

       //if only one element present in the first list
        if(first->next ==NULL){
            first->next = second;
            return first;
        }
        
        Node* curr1 = first;
        Node* next1 = curr1 -> next;
        Node* curr2 = second;
        Node* next2 = curr2 -> next;

        while(next1 !=NULL && curr2!=NULL){
            if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 ->data)){
                //add nodes in between first list
                curr1->next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1;
                 //update pointers
                 curr1 = curr2;
                 curr2 = next2;
            }
            else{                     //go ahead one step in the first list
                curr1 = next1;
                next1 = next1 -> next;
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
                }
            }                  
        }
        return first;
    }

Node* sortTwoLists(Node* first, Node* second){
    if(first ==NULL)
    return second;
    if(second== NULL)
    return first;

    if(first-> data <= second->data){
      return solve(first, second);
    }
    else{
      return solve(second,first);
    }


};

int main(){
    Node* head1 = new Node(1);
    head1 ->next = new Node(3);
    head1 ->next -> next = new Node(5);

    Node* head2 = new Node(2);
    head2 ->next = new Node(4);
    head2 -> next -> next = new Node(6);

    Node* result = sortTwoLists(head1, head2);

    while(result !=NULL){
        cout<<result->data<<" ";
        result = result-> next;
    }
    return 0;
}
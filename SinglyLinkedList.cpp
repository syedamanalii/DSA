#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     
    //constructor -  for insertion
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor -  for deletion
    ~Node(){
        int value = this-> data;
        //memory free
        if(this ->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }

};

void insertAtHead(Node* &head, int d){            //reference to not make copy

    //new node create
    Node* temp = new Node(d);
    temp -> next =  head;    //temp's next pointing to head
    head = temp;             //head is now pointing to temp base
}

void insertAtTail(Node * &tail, int d){

      Node* temp = new Node(d);
      tail -> next = temp;
      tail = tail -> next;    //tail = temp;
}

void insertAtPosition(Node * &tail, Node * &head, int position, int d){
    //insert at start
    if(position ==1){
        insertAtHead(head, d);
        return;
    }

    Node * temp = head;       //due to this being on head, this alone can never insert at the first location
    int cnt = 1;
    while(cnt< position-1){
        temp = temp -> next;
        cnt++;
    }

    //insert at last position as even though last position can be updated without this, the tail would still remain the same if not updated
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }


    //creating a node for d aka inserting the node at the desired position 
    Node  *nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next;   
    temp-> next = nodeToInsert;
}

void deleteNode(int position, Node * &head){
    //deleting start node
    if(position ==1){
      Node* temp = head;
      head = head -> next;
      //memory free start node
      temp -> next = NULL;
      delete temp;
    }
    else{  
    //deleting any middle or last node
      Node *curr = head;
      Node *prev = NULL;
    
      int cnt = 1;
      while(cnt <  position){
         prev = curr;
         curr = curr-> next;
         cnt++;
      }
        if(curr != NULL){
        prev-> next = curr->next;
        curr-> next = NULL;
        delete curr;
      }
    }
}

void printNode(Node * &head){
   Node* temp = head;
   while(temp != NULL){
     cout<< temp -> data<<" "<<endl;
     temp = temp -> next;
   }
   cout<<endl;
}

int main(){
    //creating a new node
   Node* node1 = new Node(10);
  // cout<<node1 -> data<<endl;
  // cout<<node1 -> next<<endl;

   //head pointing to node1
   Node * head = node1;

   Node * tail = node1;

    printNode(head);

   insertAtHead(head, 12);
    insertAtTail(tail, 8);
    printNode(head);

   insertAtHead(head, 15);
   insertAtTail(tail, 5);
    printNode(head);


   insertAtPosition(tail, head, 4, 69);
   printNode(head); 

    deleteNode(4,head);
    printNode(head);
  
  cout<<"head "<< head->data<<endl<<"tail "<<tail->data<<endl;
  return 0;
}
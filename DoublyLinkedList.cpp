#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
        this-> data = d;
        this-> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node * &head,Node* &tail, int d){
   if(tail==NULL){
  Node * temp = new Node(d);
   tail = temp;
   head = temp;
   }
   else{
  Node* temp = new Node(d); 
  temp ->next = head;
  head->prev = temp;
  head = temp;
   }
}

void insertAtTail(Node * &head,Node * &tail, int d){
    if(tail == NULL){
    Node * temp = new Node(d);
    head = temp;
    tail = temp;
    }
    else{
    Node * temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}

void insertAtPosition(Node* &head, Node * &tail,int position, int d){
      //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node * nodeToInsert = new Node(d);
    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

//traversing a linked list
void printNode( Node* head){
    Node *temp = head;
    while(temp !=NULL){
        cout<<temp-> data<<endl;
        temp = temp-> next;
    }
    cout<<endl;
}
//gives length of linked list
int getLength(Node * head){
    int length = 0;
    Node *temp = head;
    while(temp !=NULL){
        length++;
        temp = temp-> next;
    }
    return length;
}

int main(){
    //Node* node1 = new Node(12);
    //Node *head = node1;
    //Node *tail = node1;
    Node* head = NULL;
    Node* tail = NULL;

    printNode(head);
    cout<<getLength(head)<<endl<<endl;;

     insertAtHead(tail,head, 11);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 13);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 8);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail,head, 25);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 2, 100);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    printNode(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    printNode(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    return 0;
}
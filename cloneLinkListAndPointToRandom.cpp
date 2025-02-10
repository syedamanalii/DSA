#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;  //pointing to random links
    Node(int d){
        data = d;
        next = NULL;
        random = NULL;
    }
};
class Solution{
    private:
    void insertAtTail( Node* &head, Node * &tail, int d){
        Node * newNode = new Node(d);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
   public:
   Node *copyList(Node* head){

    //step1-> create a clone list
    Node* cloneHead = NULL;
    Node*  cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL){
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp= temp->next;
    }

    //step2-> cloneNodes add in between the Original List
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL){
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;

        next = cloneNode ->next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    //step3-> random pointer copy
    temp = head;
    while(temp != NULL){
        if(temp->next != NULL){
            temp-> next -> random = temp-> random 
            ? temp-> random -> next : NULL; //OR temp ->next = temp-> random;
      
      /*      if(temp -> random !=NULL){
            temp-> next -> random = temp-> random -> next;
            }
            else{
                temp ->next = temp-> random;
            }
            */
        }
        temp = temp ->next ->next;
    }

    //step4-> revert changes done in step 2 OR revert to originalNode
    originalNode = head;
    cloneNode = cloneHead;
     while(originalNode != NULL && cloneNode != NULL){
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        
        if(originalNode !=NULL){
        cloneNode ->next = originalNode->next;
        }
        cloneNode = cloneNode ->next;
    }

    //step5-> return ans
    return cloneHead;
   }

};

int main() {
    // Create a sample linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    Solution sol;
    Node* clonedList = sol.copyList(head);

    // Print the cloned list
    Node* temp = clonedList;
    while (temp != NULL) {
        cout << "Node data: " << temp->data;
        if (temp->random != NULL) {
            cout << ", Random points to: " << temp->random->data << endl;
        } else {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }
    return 0;
}
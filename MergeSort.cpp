#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
    data = d;
    next= NULL;
    }   
};

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast -> next != NULL){
       slow = slow-> next;
       fast = fast-> next-> next; 
    }
    return slow;
} 

Node* merge(Node* left, Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left !=NULL && right != NULL){
        if( left ->data < right -> data){
            temp->next = left;
            temp = left;
            left = left ->next;
        }
        else {
            temp-> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left ->next;
    }
    while(right != NULL){
        temp-> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans ->next;
    return ans;
}

Node* mergeSort(Node *head){
    //base case
    if(head ==NULL || head ->next ==NULL){
        return head;
    }
    //break linked list into two halves, after finding mid
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid ->next;
    mid-> next = NULL;
    //recursive calls to sort both halves
     left = mergeSort(left);
     right = mergeSort(right); 

     //merge left and right parts
     Node* result = merge(left, right);

     return result; 
}

int main() {
    // Create a sample linked list
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    // Print the original list
    cout << "Original List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Sort the linked list using merge sort
    head = mergeSort(head);

    // Print the sorted list
    cout << "Sorted List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

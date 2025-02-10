 #include<iostream>
 #include<vector>
 using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

/*     //Approach 1-> time and space complexity O(N)
class Solution{
    private:
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;

        while(s<=e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;              
    }
    public:
    //function to check whther the list is palindrome
    bool isPalindrome(Node *head){
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL){
         arr.push_back(temp->data);
         temp = temp -> next;
        }

        return checkPalindrome(arr);
    }
};
*/

//Approach 2 -> time comp-> O(n), Space Comp-> O(1)
class Solution{
    private:
      Node * getMid( Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while( fast != NULL && fast-> next != NULL){
            fast = fast-> next->next;
            slow = slow-> next;
        }
        return slow;
      }

      Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr ->next = prev;
            prev = curr;
            curr = next; 
        }
        return prev;
      }
    public:
 //function to check whther the list is palindrome
      bool isPalindrome(Node *head){
        if(head->next ==NULL){
            return true;
        }
        //step1->find middle
        Node * middle = getMid(head);
        //step2->reverse list after middle
        Node *temp = middle -> next;
        middle -> next = reverse(temp);
        //step3->compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 ->next;
            head2 = head2 ->next;
        }

        //step4->repeat step 2
         Node *temp = middle -> next;
        middle -> next = reverse(temp);

        return true;
    }   
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
        } 
    else{ 
        cout << "The linked list is not a palindrome." << endl; 
        }
    return 0;
}
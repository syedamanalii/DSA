#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void convertIntoSortedDoublyLinkedList(TreeNode* root, TreeNode*& head) {
    if (root == nullptr) return;

    static TreeNode* prev = nullptr;
    convertIntoSortedDoublyLinkedList(root->left, head);

    if (prev == nullptr) {
        head = root;
    } else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    convertIntoSortedDoublyLinkedList(root->right, head);
}

TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            if (head == nullptr) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == nullptr) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != nullptr) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != nullptr) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(TreeNode* head) {
    int cnt = 0;
    TreeNode* temp = head;
    while (temp != nullptr) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode* sortedLLtoBST(TreeNode*& head, int n) {
    if (n <= 0 || head == nullptr) {
        return nullptr;
    }
    TreeNode* left = sortedLLtoBST(head, n / 2);
    TreeNode* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLtoBST(head, n - n / 2 - 1);
    return root;
}

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {

    //step 1: convert BST to DLL in place
    TreeNode* head1 = nullptr;
    convertIntoSortedDoublyLinkedList(root1, head1);
    head1->left = nullptr;
    
    TreeNode* head2 = nullptr;
    convertIntoSortedDoublyLinkedList(root2, head2);
    head2->left = nullptr;

     //step 2: merged sorted linked list
    TreeNode* mergedHead = mergeLinkedList(head1, head2);

    //step 3: convert sorted linked list to BST
    int totalNodes = countNodes(mergedHead);
    return sortedLLtoBST(mergedHead, totalNodes);
}

int main() {
    // Example usage
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);

    TreeNode* mergedRoot = mergeBST(root1, root2);

    // Inorder traversal of the merged tree
    vector<int> result;
    convertIntoSortedDoublyLinkedList(mergedRoot, mergedRoot);
    TreeNode* temp = mergedRoot;
    while (temp != nullptr) {
        result.push_back(temp->data);
        temp = temp->right;
    }
    
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

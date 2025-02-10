#include<iostream>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    //answer update
    if(currNode.isBST){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << "Size of largest BST is: " << largestBST(root) << endl;

    // Cleaning up dynamic memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

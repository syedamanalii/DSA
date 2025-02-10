#include<iostream>
#include<vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(TreeNode* root, vector<int>& in) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        ans[k++] = a[i++];
    }
    while (j < b.size()) {
        ans[k++] = b[j++];
    }
    return ans;
}

TreeNode* inorderToBST(int s, int e, vector<int>& in) {
    // Base case
    if (s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode* root = new TreeNode(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
    // Step 1: Store inorder traversals
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Step 2: Merge Both Sorted inorder traversals
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // Step 3: Convert merged inorder traversal to BST
    int s = 0, e = mergedArray.size() - 1;
    return inorderToBST(s, e, mergedArray);
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
    inorder(mergedRoot, result);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

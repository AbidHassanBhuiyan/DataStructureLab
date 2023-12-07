#include <iostream>
using namespace std;

/* Defining tree node */
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

/* Function for in-order traversal */
void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

/* Function for pre-order traversal */
void preOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

/* Function for post-order traversal */
void postOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main() {
    /* Creating a binary tree */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "In-order: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order: ";
    postOrderTraversal(root);
    cout << endl;

    /* Cleaning allocated memory */
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

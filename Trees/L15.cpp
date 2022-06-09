/*

L15. Check for Balanced Binary Tree | C++ | Java

Problem Link: https://leetcode.com/problems/balanced-binary-tree/
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    };
};

// TC: O(N) + O(N) // for traversal + to find left / right height
// SC: O(1)

int height(struct Node * root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool check(struct Node * root) {
    if(root == NULL) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(abs(leftHeight - rightHeight) > 1 ) return false;
    // check for left and right subtree
    bool leftSubTree  = check(root->left);
    bool rightSubTree = check(root->right);
    if(!leftSubTree || !rightSubTree) return false;
    return true;
}

// O(N) using height method by returning -1 if height is not proper at any stage

int checkBalanced(struct Node * root) {
    if(root == NULL) return 0;
    int leftHeight = checkBalanced(root->left);
    int rightHeight = checkBalanced(root->right);
     // if any subtree return -1, return false;
    if(leftHeight == -1 || rightHeight == -1) {
        return -1;
    }
    // at any point height is not balanced, return -1
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->left->right->right = new Node(8);
    cout << check(root) << endl;
    int height1 = checkBalanced(root);
    if(height1 == -1) {
        cout << false << endl;
    } else {
        cout << true << endl;
    }
    return 0;
}

/*
struct Node * root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->left->right->left = new Node(6);
root->right->left = new Node(7);
root->right->right = new Node(8);
root->right->right->left = new Node(9);
root->right->right->right = new Node(10);

                1
        2               3
    4       5       7       8
          6               9    10 
*/
/*

L16. Diameter of Binary Tree | C++ | Java

Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/
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

// TC: 
// SC: 

int height(struct Node * root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void findMaxi(struct Node * root, int & maxi) {
    if(root == NULL) return;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    maxi = max(maxi, lHeight + rHeight);
    findMaxi(root->left, maxi);
    findMaxi(root->right, maxi);
}

int DaimeterOfBT(struct Node * root) {
    if(root == NULL) return 0;
    int maxi = 0;
    findMaxi(root, maxi);
    return maxi;
}

int heightHelper(struct Node * root, int & maxi) {
    if(root == NULL) return 0;
    int lHeight = heightHelper(root->left, maxi);
    int rHeight = heightHelper(root->right, maxi);
    maxi = max(maxi, lHeight + rHeight);
    return 1 + max(lHeight, rHeight);
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
    cout << DaimeterOfBT(root) << endl;
    int maxi = 0;
    heightHelper(root, maxi);
    cout << maxi << endl;
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
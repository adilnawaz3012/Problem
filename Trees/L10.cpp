/*
L10. iterative Inorder Traversal in Binary Tree | C++ | Java | Stack
Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
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

// TC: O(N)
// SC: O(N)

// same logic as recursoion
// initially root is pushed to recursion satck, then we go in left
// if we reach NULL, we print it and move the root to right
void iterativeInorder(struct Node * root) {
    if(root == NULL) return;
    stack<struct Node *> stck;
    vector<int> ans;
    struct Node * node = root;
    while(true) {
        if(node != NULL) {
            stck.push(node);
            node = node->left;
        } else {
            if(stck.empty()) break;
            node = stck.top(); // node keeps changing 
            stck.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    for(auto a: ans) {
        cout << a << " ";
    }
}


int main() {
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    iterativeInorder(root);
    cout << endl;
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
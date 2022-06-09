/*

L14. Maximum Depth in Binary Tree | Height of Binary Tree | C++ | Java

Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
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

int recursiveHeight(struct Node * root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(recursiveHeight(root->left), recursiveHeight(root->right));
}

int iterativeHeight(struct Node * root) {
    int count = 0;
    if(root == NULL) return 0;
    queue<struct Node * > q;
    q.push(root);
    while(!q.empty()) {
        int s = q.size();
        count++;
        for(int i=0;i<s;i++) {
            struct Node * temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return count;
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
    cout << recursiveHeight(root) << endl;
    cout << iterativeHeight(root) << endl;
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
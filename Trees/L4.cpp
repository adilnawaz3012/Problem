/*
L4. Binary Tree Traversals in Binary Tree | BFS | DFS

**************See Hard Notes******************

*/

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

#include<bits/stdc++.h>
using namespace std;

int main() {
    struct Node * root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);
    return 0;
}
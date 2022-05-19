/*
Level Order Traversal
*/

#include<bits/stdc++.h>
using namespace std;

class node{ 
    public:
    int data;
    node * left, * right;
    // node(int data) {
    //     data = data;
    //     left = NULL;
    //     right = NULL;
    // }
};

node * newNode(int data) {
    node * Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

int height(node * root) {
    if(root == NULL) return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    return 1 + max(lHeight , rHeight);
}

void printCurrentLevel(node * root, int level) {
    if(root == NULL) return;
    if(level == 1) {
        cout << root->data << " ";
    }
    else if(level > 1) {
        printCurrentLevel(root->left, level -1 );
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(node * root) {
    int h = height(root);
    for(int i=1;i<=h;i++) {
        printCurrentLevel(root,i);
    }
}

void printLevelOrderQueue(node * root) {
    if(root == NULL) return;
    queue<node *> q;
    q.push(root);
    int res = 0;
    while(q.size()) {
        res = 0;
        for(int i=0;i<q.size();i++) {
            node * Node = q.front();
            q.pop();
            // res+= Node->data;
            cout << Node->data << " ";
            if(Node->left) q.push(Node->left);
            if(Node->right) q.push(Node->right);
        }
    }
    // cout << res << endl;
}

int main(){
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << "Level order traveral of binary tree is \n";
    printLevelOrder(root);
    cout << endl;
    printLevelOrderQueue(root);
    cout << endl;
    return 0;
}
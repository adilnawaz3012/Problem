/*
L12. Iterative Postorder Traversal using 1 Stack | C++ | Java | Binary Trees
Problem Link: 
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


void iterativePostorder(struct Node * root) {
    if(root == NULL) return;
    stack<struct Node *> s1, s2;
    s1.push(root);
    while(!s1.empty()) {
        struct Node * temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left) s1.push(temp->left); // not taking in reverse order (ie right -> left) as 2 stack will make order correct
        if(temp->right) s1.push(temp->right);
    }
    while(!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

void postOrder(struct Node * root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
    postOrder(root);
    cout << endl;
    iterativePostorder(root);
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
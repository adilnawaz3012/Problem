/*
L9. Iterative Preorder Traversal in Binary Tree | C++ | Java | Stack
Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
TC: 
SC: 

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

// Root -> Left -> Right but in stack Root -> Right -> Left
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode *> stck;
        stck.push(root);
        while(!stck.empty()) {
            TreeNode * temp = stck.top();
            stck.pop();
            ans.push_back(temp->val);
            if(temp->right) stck.push(temp->right); // instead of push left like queue, we push right in stack
            if(temp->left) stck.push(temp->left); // instead of push right like queue, we push left in stack
        }
        return ans;
    }

void iterativePreorder(struct Node * root) {
    if(root == NULL) return;
    stack<struct Node *> stck;
    stck.push(root);
    while(!stck.empty()) {
        struct Node * temp = stck.top();
        stck.pop();
        cout << temp->data << " ";
        if(temp->right) stck.push(temp->right);
        if(temp->left) stck.push(temp->left);
    }
    cout << endl;
}


int main() {
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    iterativePreorder(root);
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
/*
L8. Level Order Traversal of Binary Tree | BFS | C++ | Java
Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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

// TC: O(N) traveersal time
// SC: O(N) used to queue to store nodes while tarversing
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()) {
        int s = q.size(); // finding the size earlier is required when we need all the elements in that level
        vector<int> res;
        for(int i=0;i<s;i++) {
            TreeNode * temp = q.front();
            q.pop();
            res.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(res); // once all nodes in level are inserted, add the vector in final vector
    }
    return ans;
}

void levelOrderBFS(struct Node * root) {
    if(root == NULL) return;
    queue<struct Node * > q;
    q.push(root);
    while(!q.empty()) {
        struct Node * temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    levelOrderBFS(root);
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
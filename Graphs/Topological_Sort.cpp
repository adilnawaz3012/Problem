/*
Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1/#

Topological Sorting :
-> Linear ordering of vertices such that if there is an edge u->v, u appear before v in that ordering.
Only applicable for DAG 

Topological sort cannot be on cyclic graph


*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int n, vector<int> nums[], vector<int> & visited, stack<int> & stck) {
    visited[node] = 1;
    for(auto it: adj[node]) {
        if(!visited[node]) {
            dfs(it, n, nums, visited, stck);
        } 
    }
    stck.push(node);
}

void topoSort(int n, vector<int> nums[]) {
    vector<int> visited(n,0);
    stack<int> stck;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i, n, nums, visited, stck);
        }
    }
    while(!stck.empty()) {
        cout << stck.top() << " ";
        stck.pop();
    }
    cout << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<int> nums[n+1];
        for(int i=0;i<m;i++) {
            int x, y;
            cin >> x >> y;
            nums[x].push_back(y);
        }
        topoSort(n, nums);
        cout << endl;
    }
    return 0;
}
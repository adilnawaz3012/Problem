/*
Cycle Detection in Undirected Graph using DFS
Problem Link:  https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

1. Similar to DFS
2. Only keep NOTE that if node is not visited , call for further deep dfs call and if that call returns true, return true;

*/

#include<bits/stdc++.h>
using namespace std;

bool check(int node, int parent, vector<int> adj[], vector<int> & visited) {
    visited[node] = 1;
    for(auto it: adj[node]) {
        if(!visited[it]) {
            if (check(it, node, adj, visited)) return true; // **** KEEP THIS POINT IN NODE ****
        } else if(it != parent) {
            return true;
        }
    }
    return false;
}

bool cycleDetection(int n, int m, vector<int> adj[], vector<int> & visited) {
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            if(check(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
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
            nums[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        cout << cycleDetection(n,m,nums,vis) << endl;
    }
    return 0;
}


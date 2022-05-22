/*
Bipartite Graph (DFS) | Graph Coloring

Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#

*/

#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int src, vector<int> adj[], vector<int> & color) {
    if(color[src] == -1) color[src] = 1; // this check is required when inner dfs get called, else all the inner node will be marked as 1
    for(auto it: adj[src]) {
        if(color[it] == -1) {
            color[it] = 1 - color[src];
            if(!isBipartite(it, adj, color)) return false;
        } else if(color[it] == color[src]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int n, int m, vector<int> adj[]) {
    vector<int> color(n, -1);
    for(int i=0;i<n;i++) {
        if(color[i] == -1) {
            if(!isBipartite(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
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
        cout << isBipartite(n,m,nums) << endl;
    }
    return 0;
}

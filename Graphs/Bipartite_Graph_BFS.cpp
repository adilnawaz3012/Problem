/*
Bipartite Graph (BFS) | Graph Coloring

Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1/#

Self explanatory.

Keep coloring next element opp of previous.

TC::

2
4 4
0 2
0 3
1 3
2 3
4 4
0 1
0 3
1 2
1 3



*/

#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int src, vector<int> adj[], vector<int> & color) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int n, int m, vector<int> adj[]) {
    vector<int> color(n, -1);
    for(int i=0;i<n;i++) {
        if(color[i] != -1) {
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

/*
Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

NOTE:
1. Keep another dfsVisited array for additional check
2. Once we reach a stage where node has no ougoing edge, mark the node as 0 in dfsVisited array
3. Once we keep on traveersing nodes, keep marking the node as 1 in visited and dfsVisited array
4. Put a check, if both visited and dfsVisited array is marked as 1, then there is a loop
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int node, vector<int> adj[], vector<int> & visited, vector<int> & dfsVisited) {
    visited[node] = 1;
    dfsVisited[node] = 1;
    for(auto it: adj[node]) {
        if(!visited[it]) {
            if(check(it, adj, visited, dfsVisited)) return true;
        } else if(dfsVisited[it]) {
            return true;
        }
    }
    dfsVisited[node] = 0;
    return false;
}

bool cycleDetection(int n, int m, vector<int> adj[]) {
    vector<int> visited(n,0);
    vector<int> dfsVisited(n,0);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(check(i, adj, visited, dfsVisited)) {
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
        }
        cout << cycleDetection(n,m,nums) << endl;
    }
    return 0;
}
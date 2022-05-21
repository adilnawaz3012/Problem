/*
Depth-First Dearch (DFS) | Traversal Technique in Graph

TC: 

1
7 6
1 2
2 4
2 7
4 6
7 6
3 5


*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> & vis, vector<int> nums[], vector<int> & storeDfs) {
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it: nums[node]) {
        if(!vis[it]) {
            dfs(it, vis, nums, storeDfs);
        }
    }
}

void dfsOfraph(int n, int m, vector<int> nums[], vector<int> & vis) {
    vector<int> storeDfs;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i, vis, nums, storeDfs);
        }
    }
    for(auto s: storeDfs) {
        cout << s << " ";
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
            nums[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        dfsOfraph(n,m,nums,vis);
    }
    return 0;
}
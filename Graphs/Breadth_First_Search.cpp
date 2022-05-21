/*
Breadth-First Search (BFS) | Traversal Technique in Graphs

NOTE: BFS is basically traversing adjacent nodes first

FOR BFS ,we always take a queue

TC: N + E  -> N is the time taken for visiting N nodes, and E is for travelling through adjacent nodes overall 
SC: [N + E ] + [N] + [N] -> Space for adj list , vis array and queue 


TC:

1
5 7
1 2
2 4
2 3
1 3
3 4
1 5
5 3


*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int n, int m, vector<int> nums[], vector<int> & vis) {
    vector<int> bfs;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: nums[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    for(auto b: bfs) {
        cout << b << " ";
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
        int n, m;
        cin >> n >> m;
        vector<int> nums[n+1];
        for(int i=0;i<m;i++) {
            int x,y;
            cin >> x >> y;
            nums[x].push_back(y);
            nums[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        bfs(n,m,nums,vis);
    }
    return 0;
}


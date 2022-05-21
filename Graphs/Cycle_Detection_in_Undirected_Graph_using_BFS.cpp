/*
Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

NOTE:
1. Smilar to BFS
2. queue will be queue<pair<int,int>> q ( as to store current node and its parent)
3. For staring nodes, make parent as -1 as it doesn;t have any parent
4. If its adjacent nodes are visited, mark them visited and push it in queue making it parent nodes
5. If adjacent node is visited and it's adjacent node is not its parent node, return true;
( 1 - 2 ) can'e be loop as 2 came from 1

TC:

2
11 10
1 2
2 4
3 5
5 6
6 7
7 8
8 9
9 10
10 5
8 10
11 10
1 2
2 4
3 5
5 6
6 7
7 8
8 9
9 10
8 10


*/

#include<bits/stdc++.h>
using namespace std;

bool isCycle(int s, vector<int> adj[], vector<int> & visited) {
    queue<pair<int, int>> q;
    q.push({s, -1});
    visited[s] = 1;
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        for(auto it: adj[p.first]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push({it, p.first});
            } else {
                if(it != p.second) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool cycleDetection(int n, int m, vector<int> adj[], vector<int> & visited) {
    for(int i=1; i<=n;i++) {
        if(!visited[i]) {
            if(isCycle(i, adj, visited)) {
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
/*
Shortest Path in Undirected Graph with Unit Weights
Find the shortest disatnce from given node to every other node

TC:

1
9 11
0 3
0 1
1 2
3 6
0 3
3 4
4 5
5 6
1 3
6 7
7 8
8 6

Do BFS and if current distance it more than 1 + parent node sidtance,
then updatte the new distance and push the node into the queue.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int start, int end, int n, int res, int & ans, vector<int> adj[], vector<int> & visited) {
    visited[start] = 1;  
    if(start == end) {
        ans = min(ans, res);
        return;
    }
    for(auto it: adj[start]) {
        if(!visited[it])
        dfs(it, end, n, res + 1, ans, adj, visited);
    }
}

int sortestPath(int start, int end, int n, vector<int> adj[]) {
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            if(distance[it] > 1 + distance[node]) {
                distance[it] = 1 + distance[node];
                q.push(it);
            }
        }
    }
    return distance[end];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n,m, start, end;
        cin >> n >> m;
        cin >> start >> end;
        vector<int> nums[n+1];
        for(int i=0;i<m;i++) {
            int x, y;
            cin >> x >> y;
            nums[x].push_back(y);
            nums[y].push_back(x);
        }
        cout << sortestPath(start, end, n, nums);
    }
    return 0;
}
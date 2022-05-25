/*
Dijkstra's Algorithm | Shortest Path in Undirected Graphs

*/

#include<bits/stdc++.h>
using namespace std;

void sortestPath(int start, int end, int n, vector<pair<int, int>> adj[]) {
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: adj[node]) {
            int child = it.first;
            int cost = it.second;
            if(distance[child] > distance[node] + cost) {
                distance[child] = distance[node] + cost;
                q.push(child);
            }
        }
    }
    for(auto d: distance) {
        cout << d << " ";
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
        int n,m, start, end;
        cin >> n >> m;
        cin >> start >> end;
        vector<pair<int,int>> nums[n+1];
        for(int i=0;i<m;i++) {
            int x, y, cost;
            cin >> x >> y >> cost;
            nums[x].push_back({y,cost});
            nums[y].push_back({x,cost});
        }
        sortestPath(start, end, n, nums);
    }
    return 0;
}
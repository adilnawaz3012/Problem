/*
Shortest Path in Directed Acyclic Graph (DAG)

AKA: Shortest path in a weighted DAG

REVISIT AGAIN AS SOLUTION IS DIFF FROM WHAT TAUGHT

TC:

4
6 7
0 2
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
6 7
4 3
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
6 7
0 5
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1
6 7
0 3
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1


*/

#include<bits/stdc++.h>
using namespace std;

int sortestPath(int start, int end, int n, vector<pair<int, int>> adj[]) {
    vector<int> distance(n,INT_MAX);
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
        vector<pair<int,int>> nums[n+1];
        // vector<vector<int, 
        for(int i=0;i<m;i++) {
            int x, y, cost;
            cin >> x >> y >> cost;
            // nums[x].push_back(y);
            nums[x].push_back({y,cost});
        }
        cout << sortestPath(start, end, n, nums) << endl;
    }
    return 0;
}
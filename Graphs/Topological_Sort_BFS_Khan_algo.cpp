/*
Topological Sort (BFS) | Kahn's Algorithm

TC: N + E
SC: N + N

TC:

1
6 6
2 3
3 1
4 0
4 1
5 0
5 2

Self Explanatory
*/

#include<bits/stdc++.h>
using namespace std;

void topoSort(int n, vector<int> nums[]) {
    queue<int> q;
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++) {
        for(auto it: nums[i]) {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: nums[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    for(auto t: topo) {
        cout << t << " ";
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
        }
        topoSort(n, nums);
        cout << endl;
    }
    return 0;
}
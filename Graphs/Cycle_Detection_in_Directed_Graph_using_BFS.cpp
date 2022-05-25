/*
Cycle Detection in Directed Graph using BFS(Kahn's Algorithm)

TC: 

2
6 6
2 3
3 1
4 0
4 1
5 0
5 2
4 4
0 1
1 2
2 3
3 1

Note: Just check it topo is generatated or not
if generated meand no cycle else cycle

*/

#include<bits/stdc++.h>
using namespace std;

int topoSort(int n, vector<int> nums[]) {
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
    // vector<int> topo;
    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // topo.push_back(node);
        count++;
        for(auto it: nums[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    /*
    if count == n, it means it generated the topo sort with all element, so cycle will be false
    */
    if(count == n) return false;
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
        }
        int res = topoSort(n, nums);
        if(res == 0) {
            cout << "Doesn't contain cycle\n";
        } else {
            cout << "Contain cycle\n";
        }
    }
    return 0;
}
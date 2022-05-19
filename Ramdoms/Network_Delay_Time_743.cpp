/*
https://leetcode.com/problems/network-delay-time/

NOTE: initialise all nodes with max value distance and disitance from k to k be 0
loop through all the nodes and keep updating the mininum distance from one node to other

if a source node is visited and previous distance from source node + distance from source node to distination node is less than current distination node
then update the desination node distance

At last loop though all the nodes disance and find the maximun out of all the nodes distance.

TC:

3
4 2
2 1 1
2 3 1
3 4 1
2 1
1 2 1
2 2
1 2 1

*/


#include<bits/stdc++.h>
using namespace std;

int networkDelayTime1(vector<vector<int>> & times, int n, int k){
    if(times.size() == 0) {
        return -1;
    }
    vector<int> visited(n+1, INT_MAX);
    int result = 0;
    visited[k] = 0;
    for(int i=1;i<=n;i++) {
        for(auto time: times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            if(visited[u] != INT_MAX && visited[v] > visited[u] + w) {
                visited[v] = visited[u] + w;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        result = max(result, visited[i]);
    }
    return result == INT_MAX ? -1 : result;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    if (times.size() == 0) {
        return -1;
    }
    vector<int> dp(n+1, INT_MAX);
    dp[k] = 0;
    
    // traverse all destinations
    for(int i=0; i<n; i++) {
        for(auto edge: times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dp[u] != INT_MAX && dp[v] > dp[u] + w) {
                dp[v] = dp[u] + w;
            }
        }
    }
    
    /*
    after getting minimum distance (tarvel time) to all points, we should retrieve the max distance from these minimum distance, to ensure that we can travel all poinyts in a specific tarval times
    */
    int result = 0;
    for(int i=1; i<=n;i++) {
        result = max(result, dp[i]);
    }
    return result == INT_MAX ? -1 : result;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> times;
        int u,v,w;
        vector<int> temp;
        for(int i=0;i<n;i++) {
            cin >> u >> v >> w;
            temp = {u,v,w};
            times.push_back(temp);
        }
        cout << networkDelayTime(times, n, k) << endl;
        cout << networkDelayTime1(times, n, k) << endl;
    }
    return 0;
}
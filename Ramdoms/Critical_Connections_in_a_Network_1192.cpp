/*
https://leetcode.com/problems/critical-connections-in-a-network/

Intution:

*/

#include<bits/stdc++.h>
using namespace std;

void criticalConnections(int n, vector<vector<int>> & connections) {
    int size = connections.size();
    if(size == 1) {
        cout << connections[0][0] << " " << connections[0][1] << endl;
        return;
    }

};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> connections(n, vector<int>(2,0));
        for(int i=0;i<n;i++) {
            cin >> connections[i][0] >> connections[i][1];
        }
        criticalConnections(n, connections);
    }
    
    return 0;
}
/*
1. Using adjacency matrix ( only for smaller values )
Can we one ( 1 based ) or ( 0 based)
1 based -> nodes will be 1 2 3 4 5
0 based -> nodes will be 0 1 2 3 4

2. Adjacancy List ( for larger value ) vector<int> arr[6]
In case for weight

vector<pair<int, int>> arr[6]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int> (n+1, 0));
    vector<vector<int>> ip(m, vector<int>(2,0));
    for(int i=0;i<m;i++) {
        cin >> ip[i][0] >> ip[i][1];
    }
    for(int i=0;i<m;i++) {
        int x = ip[i][0];
        int y = ip[i][1];
        adj[x][y] = adj[y][x] = 1;
    }
    for(auto ad: adj) {
        for(auto a: ad) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;

    // SC : N + 2 E
    vector<vector<int>> temp(n+1, vector<int>(0));
    for(int i=0;i<m;i++) {
        int x = ip[i][0];
        int y = ip[i][1];
        temp[x].push_back(y);
        temp[y].push_back(x); 
    }
    for(int i=0;i<temp.size();i++) {
        cout << i << " -> ";
        if(temp[i].size()) {
            for(auto a: temp[i]) {
                cout << a << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
/*


*/

#include<bits/stdc++.h>
using namespace std;

void sumOfDistancesInTree(int n, vector<vector<int>> & edges, vector<int> & ans) {
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n - 1, vector<int>(2,0));
        for(int i=0;i<n -1;i++) {
            cin >> edges[i][0] >> edges[i][1];
        }
        vector<int> ans(n,0);
        sumOfDistancesInTree(n, edges, ans);
    }
    return 0;
}
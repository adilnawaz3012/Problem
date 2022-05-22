/*

*/

#include<bits/stdc++.h>
using namespace std;

void topoSort(int n, vector<int> nums[]) {
    for(int i=0;i<n;i++) {
        
    }
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
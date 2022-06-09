/*
DP 47. Number of Longest Increasing Subsequences


*/

#include<bits/stdc++.h>
using namespace std;

int no_of_lis(vector<int> & nums) {
    int n = nums.size();
    vector<int> dp(n,1);
    unordered_map<int, int> umap;
    int maxi = 1;
    umap.insert({1, 1});
    for(int i=0;i<n;i++) {
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                maxi = max(maxi, dp[i]);
            }
        }
        cout << dp[i] << " ";
        if(umap.find(dp[i]) != umap.end()) {
            umap[dp[i]]++;
        } else {
            umap.insert({dp[i], 1});
        }
    }
    cout << endl;
    return umap[maxi];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << no_of_lis(nums) << endl;
    }
    return 0;
}
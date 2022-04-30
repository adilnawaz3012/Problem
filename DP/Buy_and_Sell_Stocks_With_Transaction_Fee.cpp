// Buy and Sell Stocks With Transaction Fee 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include<bits/stdc++.h>
using namespace std;

int Recursion(vector<int> & nums, int idx, int buy, int fee) {
    if(idx ==  nums.size()) {
        return 0;
    }
    if (buy) {
        return max( -nums[idx] + Recursion(nums, idx +  1, 0 , fee), 
         0 + Recursion(nums, idx + 1, 1, fee));
    }
    return max( nums[idx] - fee + Recursion(nums, idx + 1, 1, fee), 
        0 + Recursion(nums, idx + 1, 0, fee));
}

int Memoization(vector<int> & nums, int idx, int buy, int fee, vector<vector<int>> & ds) {
    if(idx ==  nums.size()) {
        return 0;
    }
    if(ds[idx][buy] != -1) return ds[idx][buy];
    if (buy) {
        return  ds[idx][buy] = max( -nums[idx] + Memoization(nums, idx +  1, 0 , fee ,ds), 
         0 + Memoization(nums, idx + 1, 1, fee, ds));
    }
    return  ds[idx][buy] = max( nums[idx] - fee + Memoization(nums, idx + 1, 1, fee ,ds), 
        0 + Memoization(nums, idx + 1, 0, fee, ds));
}

int Tabulation(vector<int> & nums, int fee) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(2,0));
    for(int idx = n-1; idx>=0; idx--) {
        dp[idx][1] = max( -nums[idx] + dp[idx +  1][0], 
         0 + dp[idx + 1][1]);
        dp[idx][0] = max( nums[idx] - fee + dp[idx + 1][1], 
            0 + dp[idx + 1][0]);
    }
    return dp[0][1];
}

int SpaceOp(vector<int> & nums, int fee) {
    int n = nums.size();
    vector<int> after(2,0);
    vector<int> curr(2,0);
    for(int idx = n-1; idx>=0; idx--) {
        curr[1] = max( -nums[idx] + after[0], 
            0 + after[1]);
        curr[0] = max( nums[idx] - fee + after[1], 
            0 + after[0]);
        after = curr;
    }
    return after[1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, fee;
        cin >> n >> fee;
        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << "Recursion : " << Recursion(nums, 0, 1, fee) << endl;
        vector<vector<int>> ds(n+1, vector<int>(2,-1));
        cout << "Memoization : " << Memoization(nums, 0, 1, fee, ds) << endl;
        cout << "Tabulation : " << Tabulation(nums, fee) << endl;
        cout << "SpaceOp : " << SpaceOp(nums, fee) << endl;
    }
    return 0;
}
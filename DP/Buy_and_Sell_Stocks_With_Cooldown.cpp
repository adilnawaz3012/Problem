// Buy and Sell Stocks With Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<bits/stdc++.h>
using namespace std;

int Recursion(vector<int> & nums, int idx, int buy) {
    if(idx >= nums.size()) {
        return 0;
    }
    int profit;
    if (buy) {
        int take = -nums[idx] + Recursion(nums, idx + 1, 0);
        int not_take = 0 + Recursion(nums, idx + 1, 1);
        profit = max(take, not_take);
    } else {
        // only change is here is during selling
        // normally we do idx + 1, but due to cooldown, we need to do
        // idx + 2, and move to next of next
        int take = nums[idx] + Recursion(nums, idx + 2, 1); // change
        int not_take = 0 + Recursion(nums, idx + 1, 0);
        profit = max(take, not_take);
    }
    return profit;
} 

int Memoization(vector<int> & nums, int idx, int buy, vector<vector<int>> & ds) {
    if(idx >= nums.size()) {
        return 0;
    }
    if(ds[idx][buy] != -1) return ds[idx][buy];
    int profit;
    if (buy) {
        int take = -nums[idx] + Recursion(nums, idx + 1, 0);
        int not_take = 0 + Recursion(nums, idx + 1, 1);
        profit = max(take, not_take);
    } else {
        int take = nums[idx] + Recursion(nums, idx + 2, 1); // change
        int not_take = 0 + Recursion(nums, idx + 1, 0);
        profit = max(take, not_take);
    }
    return ds[idx][buy] = profit;
}

int Tabulation(vector<int> & nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    for(int idx=n-1; idx>=0; idx--) {
        for(int buy=0; buy<=1; buy++) {
            if (buy) {
                int take = -nums[idx] + dp[idx + 1][0];
                int not_take = 0 + dp[idx + 1][1];
                dp[idx][buy] = max(take, not_take);
            } else {
                int take = nums[idx] + dp[idx + 2][1]; // change
                int not_take = 0 + dp[idx + 1][0];
                dp[idx][buy] = max(take, not_take);
            }
        }
    }
    return dp[0][1]; // not returnnig dp[0][0] as [0][0] tell we are selling without buying.
}

int SpaceOp(vector<int> & nums) {
    int n = nums.size();
    vector<int> after1(2, 0);
    vector<int> after2(2, 0);
    vector<int> curr(2, 0);
    for(int idx=n-1; idx>=0; idx--) {
        int take = -nums[idx] + after1[0];
        int not_take = 0 + after1[1];
        curr[1] = max(take, not_take);
        take = nums[idx] + after2[1]; // change
        not_take = 0 + after1[0];
        curr[0] = max(take, not_take);
        after2 = after1;
        after1 = curr;
    }
    return curr[1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
        cout << "Recursion : " << Recursion(nums, 0, 1) << endl;
        vector<vector<int>> ds(n, vector<int>(2, -1));
        cout << "Memoization : " << Memoization(nums, 0, 1, ds) << endl;
        cout << "Tabulation : " << Tabulation(nums) << endl;
        cout << "SpaceOp : " << SpaceOp(nums) << endl;
    }

}
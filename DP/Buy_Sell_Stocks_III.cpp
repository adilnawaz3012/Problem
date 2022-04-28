/*
Buy and Sell Stocks III 
Note: At max 2 transactions
Similar to Knapsack where we are bound to have a max weight,
Here max transaction is 2, so keep amother variable (cap = 2), 
and its value will only decreae when we sell as buying a stock doesn;t compleates a tracsaction.
Refer Recusion method for more detailed explanation
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

#include<bits/stdc++.h>
using namespace std;

int Recursion(vector<int> & nums, int idx, int buy, int transaction) {
    if (transaction == 0) {
        // since we exhausted the max. number of tracsaction,
        // so return 0;
        return 0;
    }   

    if (idx == nums.size()) {
        // it means we completed the transaction, so we don;t get anything from the market.
        // so return 0;
        return 0;
    }
    int profit;
    if (buy) {
        int take = -nums[idx] + Recursion(nums, idx + 1, 0, transaction);
        int not_take = 0 + Recursion(nums, idx + 1, 1, transaction);
        profit = max(take, not_take);
    } else {
        int take = nums[idx] + Recursion(nums, idx + 1, 1, transaction - 1);
        int not_take = 0 + Recursion(nums, idx + 1, 0, transaction);
        profit = max(take, not_take);
    }
    return profit;
}

int Memoization(vector<int> & nums, int idx, int buy, int transaction, vector<vector<vector<int>>> & ds) {
    if(transaction == 0) {
        return 0;
    }
    if(idx == nums.size()) {
        return 0;
    }
    if(ds[idx][buy][transaction] != -1) return ds[idx][buy][transaction];
    int profit;
    if (buy) {
        int take = -nums[idx] + Memoization(nums, idx + 1, 0, transaction, ds);
        int not_take = 0 + Memoization(nums, idx + 1, 1, transaction, ds);
        profit = max(take, not_take);
    } else {
        int take = nums[idx] + Memoization(nums, idx + 1, 1, transaction - 1, ds);
        int not_take = 0 + Memoization(nums, idx + 1, 0, transaction , ds);
        profit = max(take, not_take);
    }
    return ds[idx][buy][transaction] = profit;
}

int Tabulation(vector<int> & nums) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3,0)));
    // BASE CASES:
    // for transaction = 0 . idx and buy can be anything
    for(int idx=0;idx<=n;idx++) {
        for(int buy=0;buy<=1;buy++) {
            dp[idx][buy][0]  = 0;
        }
    }
    // when idx == n, buy and transaction can be anything
    for(int buy=0;buy<=1;buy++) {
        for(int transaction=0;transaction<=2;transaction++) {
            dp[n][buy][transaction] = 0; 
        }
    }
    int profit;
    for(int idx=n-1; idx >= 0; idx--) {
        for(int buy=0; buy<=1; buy++) {
            // transaction starting from 1 as for value 0 =, its already 0
            for(int transaction=1; transaction<=2; transaction++) {
                if (buy) {
                    int take = -nums[idx] + dp[idx + 1][0][transaction];
                    int not_take = 0 + dp[idx + 1][1][transaction];
                    profit = max(take, not_take);
                } else {
                    int take = nums[idx] + dp[idx + 1][1][transaction - 1];
                    int not_take = 0 + dp[idx + 1][0][transaction];
                    profit = max(take, not_take);
                }
                dp[idx][buy][transaction] = profit;
            }
        }
    }
    return dp[0][1][2];
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
        vector<int> nums(n,0);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << "Recursion : " << Recursion(nums, 0, 1, 2) << endl;
        // vector<vector<int>> ds(n+1, vector<int>(2,-1));
        vector<vector<vector<int>>> ds(n+1, vector<vector<int>>(2, vector<int> (3, -1)));
        cout << "Memoization : " << Memoization(nums, 0, 1, 2, ds) << endl;
        cout << "Tabulation : " << Tabulation(nums) << endl;
    }
    return 0;
}
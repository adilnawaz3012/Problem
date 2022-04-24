// Buy and Sell Stock - II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Either have 2 choices whether to buy or not,
// or sell or not.
// since we need to find all possible ways, so do recursion. [ Greedy will also work ]



#include<bits/stdc++.h>
using namespace std;

// TC: 2^N
// SC: N
int Recursion(vector<int> & nums, int idx, int buy) {
    if (idx == nums.size() -1) {
        if(buy) {
            return 0;
        } else {
            return nums[idx];
        }
    }
    int profit;
    if(buy) {
        // -nums[idx] because we are buying, so money subtracted
        int take = -nums[idx] + Recursion(nums, idx + 1, 0);
        int not_take = 0 + Recursion(nums, idx + 1, 1);
        profit = max(take, not_take);
    } else {
        // +nums[idx]  because we are selling , so money added.
        int take = nums[idx] + Recursion(nums, idx +  1, 1);
        int not_take = 0 + Recursion(nums, idx + 1, 0);
        profit = max(take, not_take);
    }
    return profit;
}

// TC: N * 2
// SC: N *2 + N
int Memoization(vector<int> & nums, int idx, int buy, vector<vector<int>> & ds) {
    if(idx == nums.size()) {
        return 0;
    }
    if(ds[idx][buy] != -1) return ds[idx][buy];
    int profit;
    if (buy) {
        int take = -nums[idx] + Memoization(nums, idx +1, 0, ds);
        int not_take = 0 + Memoization(nums, idx + 1, 1, ds);
        profit = max(take, not_take);
    } else {
        int take = nums[idx] + Memoization(nums, idx + 1, 1, ds);
        int not_take = 0 + Memoization(nums, idx + 1, 0, ds);
        profit = max(take, not_take);
    }
    return ds[idx][buy] = profit;
}

/*
1. Base Case
2. Write all the changing paramters : idx, buy
3. Copy Recursion
4. 0 -> n, but reverse in Tabulation n -> 0
// TC: N * 2
// SC: N * 2  
*/

int Tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for(int idx=n-1;idx>=0;idx--) {
        for(int buy=0; buy<=1;buy++) {
            int profit;
            if (buy) {
                int take = -nums[idx] + dp[idx +1][0];
                int not_take = 0 + dp[idx + 1][1];
                profit = max(take, not_take);
            } else {
                int take = nums[idx] + dp[idx + 1][1];
                int not_take = 0 + dp[idx + 1][0];
                profit = max(take, not_take);
            }
            dp[idx][buy] = profit;
        }
    }
    return dp[0][1]; // not returnnig dp[0][0] as [0][0] tell we are selling without buying.
}

int SpaceOptimization(vector<int> & nums) {
    int n = nums.size();
    vector<int> ahead(2,0), curr(2,0);
    ahead[0] = ahead[1] = 0;
    for(int idx=n-1;idx>=0;idx--) {
        for(int buy=0; buy<=1;buy++) {
            int profit;
            if (buy) {
                int take = -nums[idx] + ahead[0];
                int not_take = 0 + ahead[1];
                profit = max(take, not_take);
            } else {
                int take = nums[idx] + ahead[1];
                int not_take = 0 + ahead[0];
                profit = max(take, not_take);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

// Sinmple using if else and buyting and selling whenever a prices drop occurs.

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;
    int lowest = prices[0];
    int profit = 0;
    for(int i=1;i<n;i++) {
        if(prices[i] < lowest) {
            lowest = prices[i]; 
        }
        if(prices[i] - lowest > 0) {
            profit += prices[i] - lowest;
            lowest = prices[i];
        }
    }
    return profit;
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
        cout << "Recusion : " << Recursion(nums, 0, 1) << endl;
        vector<vector<int>> ds(n, vector<int> (2, -1));
        cout << "Memoization : " << Memoization(nums, 0, 1, ds) << endl;
        cout << "Tabulation : " << Tabulation(nums) << endl;
        cout << "Space Optimization : " << SpaceOptimization(nums) << endl;
    }
    return 0;
}
/*
Buy and Stock Sell IV
at most k transactions


*/

#include<bits/stdc++.h>
using namespace std;

// 1
int maxProfit(vector<int> & nums, int k) {
    int n = nums.size();
    vector<vector<int>> after(2, vector<int> (k+1, 0));
    vector<vector<int>> curr(2, vector<int> (k+1, 0));

    for(int idx = n-1; idx >= 0; idx--) {
        for(int buy=0;buy<=1;buy++) {
            for(int cap=1;cap<=k;cap++) {
                if(buy == 1) {
                    curr[buy][cap] = max( -nums[idx] + after[0][cap],
                            0 + after[1][cap]);
                } else {
                    curr[buy][cap] = max( nums[idx] + after[1][cap - 1] ,
                                0 + after[0][cap]);
                }
            }
            after = curr;
        }
    }
    return after[1][k];
}

// 2 -> using N + (2 * k )
int Recursion(vector<int> & nums, int idx, int transNo, int k) {
    if(idx == nums.size() || transNo == 2 * k) {
        return 0;
    }
    if(transNo % 2 == 0 ) {
        // buy
        return max( -nums[idx] + Recursion(nums, idx + 1, transNo + 1, k) , 
                    0 + Recursion(nums, idx+ 1, transNo, k) );
    }
    return max( nums[idx] + Recursion(nums, idx+1, transNo + 1, k),
            0 + Recursion(nums, idx + 1, transNo, k));
}

// Memoization
int Memoization(vector<int> & nums, int idx, int transNo, int k, vector<vector<int>> & ds) {
    if(idx == nums.size() || transNo == 2 * k) {
        return 0;
    }
    if (ds[idx][transNo] != -1) return ds[idx][transNo];

    if (transNo % 2 == 0) {
        return ds[idx][transNo] = max( -nums[idx] + Memoization(nums, idx + 1, transNo + 1, k, ds),
            0 + Memoization(nums, idx + 1, transNo, k, ds));
    }
    return ds[idx][transNo] = max(nums[idx] + Memoization(nums, idx + 1, transNo + 1, k ,ds) ,
            0 + Memoization(nums, idx + 1, transNo, k, ds));
}

int Tabulation(vector<int> & nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(2 * k + 1, 0));
    // no initialization as all base cases are zero
    for(int idx = n-1; idx >=0; idx--) {
        for(int transNo=0; transNo< 2*k; transNo++) {
            if (transNo % 2 == 0) {
                dp[idx][transNo] = max( -nums[idx] + dp[idx + 1][transNo + 1],
                    0 + dp[idx + 1][transNo]);
            } else {
                dp[idx][transNo] = max(nums[idx] +dp[idx + 1][transNo + 1],
                    0 + dp[idx + 1][transNo]);
            }
        }
    }
    // dp[0][0] because, going from bottom to top, and next 0 is the case when we are left with no transaction left;
    return dp[0][0];
}

int SpaceOp(vector<int> & nums, int k) {
    int n = nums.size();
    vector<int> after(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);
    // no initialization as all base cases are zero
    for(int idx = n-1; idx >=0; idx--) {
        for(int transNo=0; transNo< 2*k; transNo++) {
            if (transNo % 2 == 0) {
                curr[transNo] = max( -nums[idx] + after[transNo + 1],
                    0 + after[transNo]);
            } else {
                curr[transNo] = max(nums[idx] + after[transNo + 1],
                    0 + after[transNo]);
            }
        }
        after = curr;
    }
    return after[0];
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << "Max Profit : " << maxProfit(nums, k) << endl;
        // using N * (2 * k)
        cout << "Recursion : " << Recursion(nums, 0, 0, k) << endl;
        vector<vector<int>> ds(n+1, vector<int>(2*k, -1));
        cout << "Memoization : " << Memoization(nums, 0, 0, k, ds) << endl;
        cout << "Tabulation : " << Tabulation(nums, k) << endl;
        cout << "SpaceOp : " << SpaceOp(nums, k) << endl;
    }
    return 0;   
}
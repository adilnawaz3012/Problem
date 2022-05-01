// Printing Longest Increasing Subsequence | Tabulation | Algorithm
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

// move second paramter of dp to idx -> idx + 1 and prevIdx -> prevIdx + 1

int Tabulation(vector<int> & nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int idx=n-1;idx>=0;idx--) {
        for(int prevIdx=idx -1; prevIdx>=-1;prevIdx--) {
            int take = INT_MIN;
            if(prevIdx == -1 || nums[prevIdx] < nums[idx]) {
                take = 1 + dp[idx+1][idx+1];
            }
            int not_take = 0 + dp[idx + 1][prevIdx + 1];
            dp[idx][prevIdx + 1] = max(take, not_take);
        }
    }
    return dp[0][-1 + 1];
}

int LIS(vector<int> & nums) {
    int n = nums.size();
    int maxi = 1;
    vector<int> dp(n,1);
    for(int i=0;i<n;i++) {
        for(int prev=0; prev<i;prev++) {
            if(nums[prev] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int LIS_Print(vector<int> & nums) {
    int n = nums.size();
    int maxi = 1;
    int lastIdx = 0;
    vector<int> dp(n,1), hash(n);
    for(int i=0;i<n;i++) {
        hash[i] = i;
        for(int prev=0;prev<i;prev++) {
            if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            lastIdx = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIdx]);
    while(hash[lastIdx] != lastIdx) {
        lastIdx = hash[lastIdx];
        temp.push_back(nums[lastIdx]);
    }
    reverse(temp.begin(), temp.end());
    for(auto x: temp) {
        cout << x << " ";
    }
    cout << endl;
    return maxi;
}

int main() {
    #ifndef ONLINEJUDGE
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
        cout << "Tabulation : " << Tabulation(nums) << endl;
        cout << "LIS : " << LIS(nums) << endl;
        cout << "Print LIS : " << LIS_Print(nums) << endl;
    }
    return 0;
}
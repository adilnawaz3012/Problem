/*

*/

#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> & v1, vector<int> & v2) {
    if(v1[0] == v2[0]) {
        return v1[1] > v2[1];
    } else {
        return v1[0] < v2[0];
    }
}

class Solution {
public:
    static bool comparator(vector<int> & v1, vector<int> & v2) {
        if(v1[0] == v2[0]) {
            return v1[1] > v2[1];
        } else {
            return v1[0] < v2[0];
        }
    }

    int recursion(int idx, int prevIdx, vector<vector<int>> & nums) {
        if(idx == nums.size()) {
            return 0;
        }
        int take = INT_MIN;
        if(prevIdx == -1 || (nums[prevIdx][0] < nums[idx][0] && nums[prevIdx][1] < nums[idx][1])) {
            take = 1 + recursion(idx + 1, idx, nums);
        }
        int not_take = recursion(idx + 1, prevIdx, nums);
        return max(take, not_take);
    }
    
    int memoization(int idx, int prevIdx, vector<vector<int>> & nums, vector<vector<int>> & ds) {
        if(idx == nums.size()) {
            return 0;
        }
        if(ds[prevIdx+1][idx] != -1) return ds[prevIdx+1][idx];
        int take = INT_MIN; 
        if(prevIdx == -1 || (nums[prevIdx][0] < nums[idx][0] && nums[prevIdx][1] < nums[idx][1])) {
            take = 1 + memoization(idx + 1, idx, nums ,ds);
        }
        int not_take = memoization(idx + 1, prevIdx, nums,ds);
        return ds[prevIdx+1][idx] = max(take, not_take);
    }
    
    int Tabulation(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for(int idx = n-1; idx>=0;idx--) {
            for(int prevIdx = idx - 1; prevIdx >=-1; prevIdx--) {
                int take = INT_MIN; 
                if(prevIdx == -1 || (nums[prevIdx][0] < nums[idx][0] && nums[prevIdx][1] < nums[idx][1])) {
                    take = 1 + dp[idx + 1][idx+1];
                }
                int not_take = dp[idx + 1][prevIdx + 1];
                dp[idx][prevIdx + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
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
    
    int baap(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++) {
            for(int prev = 0; prev<i;prev++) {
                if(nums[prev][0] < nums[i][0]) {
                    if(nums[prev][1 < nums[i][1]]) {
                        dp[i] = max(dp[i], 1 + dp[prev]);
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
   
    int baap_of_baap(vector<vector<int>>& env) {
        vector<int> lis;
        
        for(int i = 0;i<env.size();i++){
            int ele = env[i][1];
            
            int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();
            
            if(idx >= lis.size()) lis.push_back(ele);
            else lis[idx] = ele;
        }
        
        return lis.size();
    }
    
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    static bool cmp1(vector<int> & a, vector<int> &b ) {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int testing(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp;
        for(int i=0;i<n;i++) {
            int ele = nums[i][0];
            int idx = lower_bound(dp.begin(), dp.end(), ele) - dp.begin();
            if(idx >= dp.size()) dp.push_back(ele);
            else dp[idx] = ele;
        }
        return dp.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // sort(envelopes.begin(), envelopes.end(), cmp);
        // vector<vector<int>> ds(n+1, vector<int>(n,-1));
        // return recursion(0, -1, envelopes);
        // return memoization(0, -1, envelopes, ds);
        // return Tabulation(envelopes);
        // return baap(envelopes);
        // return baap_of_baap(envelopes);
        sort(envelopes.begin(), envelopes.end(), cmp1);
        return testing(envelopes);
    }
};

int recursion(int idx, int prevIdx, vector<vector<int>> & nums) {
    if(idx == nums.size()) {
        return 0;
    }
    int take = INT_MIN;
    if(prevIdx == -1 || nums[prevIdx][0] < nums[idx][0]) {
        take = 1 + recursion(idx + 1, idx, nums);
    }
    int not_take = recursion(idx + 1, prevIdx, nums);
    return max(take, not_take);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> nums(n, vector<int>(2,0));
        for(int i=0;i<n;i++) {
            cin >> nums[i][0] >> nums[i][1];
        }
        sort(nums.begin(), nums.end(), comparator);
        cout << recursion(0, -1, nums);
        cout << endl;
    }
    return 0;
}
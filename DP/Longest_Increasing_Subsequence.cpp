// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/
// NOTE: in all subsequence pattern ,we can take or not take

#include<bits/stdc++.h>
using namespace std;

int Recursion(vector<int> & nums, int idx, int prevIdx) {
    if(idx == nums.size()) {
        return 0;
    }
    int take = INT_MIN;
    if(prevIdx == -1 || nums[prevIdx] < nums[idx]) {
        take = 1 + Recursion(nums, idx+1, idx);
    }
    int not_take = 0 + Recursion(nums, idx + 1, prevIdx);
    return max(take, not_take);
}

int Memoization(vector<int> & nums, int idx, int prevIdx, vector<vector<int>> ds) {
    if(idx == nums.size()) {
        return 0;
    }
    // changed ds[idx][prevIdx] to ds[idx][prevIdx + 1] as index can't be -1 
    if(ds[idx][prevIdx + 1] != -1) return ds[idx][prevIdx + 1];
    int take = INT_MIN;
    if(prevIdx == -1 || nums[prevIdx] < nums[idx]) {
        take = 1 + Memoization(nums, idx+1, idx ,ds);
    }
    int not_take = 0 + Memoization(nums, idx + 1, prevIdx ,ds);
    return ds[idx][prevIdx + 1] = max(take, not_take);
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n;i++) {
            cin >> nums[i];
        }
        cout << "Recursion : " << Recursion(nums, 0, -1) << endl;
        // N * N+1 as we are starting prevIdx from -1
        vector<vector<int>> ds(n, vector<int>(n+1, -1));
        cout << "Memoization : " << Memoization(nums, 0, -1, ds) << endl; 
    }
    return 0;
}
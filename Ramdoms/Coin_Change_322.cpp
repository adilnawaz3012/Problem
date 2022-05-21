/*
NOTE:

Problem Link :https://leetcode.com/problems/coin-change/

if keep finding the elemnet till we reach the last element
if we reach last element, check if that coin at last index divides the target, 
if yes, return target / nums[0] 

we devide because, we need to get the coins needed , not the total ways ( in case of total case , we return 1 or 0 based on base condition)
if it cannot devide, return INT_MAX as we will not consider the combination of coins taken previously


*/

#include<bits/stdc++.h>
using namespace std;

int recursion(int idx, int n, int target, vector<int> & nums) {
    if(idx == 0) {
        if(target % nums[idx] == 0) {
            return target / nums[idx];
        } else {
            return 1e9;
        }
    }
    int take = INT_MAX;
    if(target - nums[idx] > 0) {
        take = 1 + recursion(idx, n, target - nums[idx], nums);
    }
    int not_take = 0 + recursion(idx-1, n, target, nums);
    return min(take, not_take);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, target; 
        cin >> n >> target;
        vector<int> nums(n, 0);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        int ans = recursion(n-1, n, target, nums);
        if(ans >= 1e9) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
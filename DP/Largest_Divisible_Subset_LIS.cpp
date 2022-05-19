/*
Subset -> take any element from array which satisfies the condition and no order criteria
NOTE: SORTING THE ARRAY IS REQUIRED TO FOLLOW UP WITH BELOW LOGIC
NOTE: if b/a and c/b it means c/a
Similar to LIS but now its Longest Divisible Subseqence
Refer : Print LIS Problem [ Printing_Longest_Increasing_Subsequence.cpp ]

TC:


2
3
1 2 3
4
1 2 4 8

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> & nums) {
    int n = nums.size();
    // sort the array to make it work like longest increasing susequence
    // and validate the logic, b/a, c/b then c/a
    sort(nums.begin(), nums.end());
    vector<int> dp(n+1, 1), hash(n);
    int maxi = 1;
    int lastIdx = 0;
    for(int i=0;i<n;i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev--) {
            if(nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1) {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIdx = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIdx]);
    while (hash[lastIdx] != lastIdx) 
    {
        lastIdx = hash[lastIdx];
        temp.push_back(nums[lastIdx]);
    }
    reverse(temp.begin(), temp.end);
    return temp;
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
        vector<int> ans = largestDivisibleSubset(nums);
        for(auto a: ans) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
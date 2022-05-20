// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/
// find LIS from front 
// find LIS from end
// loop through both LIS, from add them and subtract 1 as mid element will be comman for both front and end LIS

/*
TC:

2
8
1 11 2 10 4 5 2 1
5
1 2 5 3 2

*/


#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(int idx, int n, int count, vector<int> & nums) {
    if(count != 2) {
        return INT_MIN;
    } else {
        return 0;
    }
    int take = INT_MIN;
    if(idx < n - 1) {
        if(nums[idx] < nums[idx + 1]) {
            take = 1 + longestBitonicSubsequence(idx + 1, n, count, nums);
        } else {
            take = 1 + longestBitonicSubsequence(idx + 1, n, count + 1, nums);
        }
    }
    int not_take = INT_MIN;
    if(idx < n-1) {
        not_take = 0 + longestBitonicSubsequence(idx + 1,n, count, nums);
    }
    return max(take, not_take);
}

int longestBitonicSubsequencedp(int n, vector<int> & nums){
    vector<int> dp_front(n, 1);
    // int maxi = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(nums[j] < nums[i] && dp_front[i] < dp_front[j] + 1) {
                dp_front[i] = dp_front[j] + 1;
            }
        }
    }
    vector<int> dp_end(n ,1);
    for(int i=n-2;i>=0;i--) {
        for(int j=n-1; j>i; j--) {
            if(nums[j] < nums[i] && dp_end[i] < dp_end[j] + 1) {
                dp_end[i] = dp_end[j] + 1;
            }
        }
    }
    vector<int> bitonic(n,0);
    int maxi = 1;
    int k = n-1;
    while(dp_end.size()) {
        maxi = max(maxi, dp_front[k] + dp_end[k] - 1);
        dp_front.pop_back();
        dp_end.pop_back();
        k--;
    }
    return maxi;
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
        vector<int> nums(n,0);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << longestBitonicSubsequencedp(n, nums) << endl;
    }
    return 0;
}
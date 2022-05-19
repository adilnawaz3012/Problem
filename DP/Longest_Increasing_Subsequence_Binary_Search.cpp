// Longest Increasing Subsequence | Binary Search | Intuition
/*
Intution: 
Go accross all elements and try to form a subsequence.

*/

#include<bits/stdc++.h>
using namespace std;

int lisBinarySearch(vector<int> & nums) {
    vector<int> res = {nums[0]};
    for(int i=1;i<nums.size();i++){
        if(nums[i] > res.back()) {
            res.push_back(nums[i]);
        } else {
            int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
            res[idx] = nums[i];
        }
    }
    return res.size();
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
        cout << lisBinarySearch(nums) << endl;
    }
    return 0;
}
/*
1191. K-Concatenation Maximum Sum

https://leetcode.com/problems/k-concatenation-maximum-sum/


*/

#include<bits/stdc++.h>
using namespace std;

int kConcatenationMaxSum(vector<int> & nums, int k) {
    
}

int main(){
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
        cout << kConcatenationMaxSum(nums, k) << endl;
    }
    return 0;
}
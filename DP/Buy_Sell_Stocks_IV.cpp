/*
Buy and Stock Sell IV
at most k transactions


*/

#include<bits/stdc++.h>
using namespace std;

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
        cout << "Recursion : " << Recursion(nums, 0, 0, k) << endl;
    }
    return 0;   
}
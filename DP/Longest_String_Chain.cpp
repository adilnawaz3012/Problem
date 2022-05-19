/*
DP 45. Longest String Chain | Longest Increasing Subsequence | LIS
Problem Link: https://leetcode.com/problems/longest-string-chain/

TC:

3
6
a b ba bca bda bdca
5
xbc pcxbcf xb cxbc pcxbc
2
abcd dbqca

Similar to LIS , but its not subsequence, so we can sort the array
we need to write additional comparator to sirt based on string size

abcd
abc

*/

#include<bits/stdc++.h>
using namespace std;

int LIS(int n, vector<int> & nums) {
    vector<int> dp(n+1,1);
    int maxi = 1;
    for(int i=1;i<n;i++) {
        for(int j=0; j<i;j++) {
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }
    } 
    return maxi;
}

bool is_predecessor(string & first, string & second) {
   if(first.size() != second.size() + 1) return false;
   int i = 0;
   int j = 0;
   while(i < first.size()) {
       if(j < second.size() && first[i] == second[j]) {
           i++;
           j++;
       } else {
           i++;
       }
   }
   if(i == first.size() && j == second.size()) {
       return true;
   }
   return false;
}

bool comparator(string & s1, string & s2) {
    return s1.size() < s2.size();
}

int longestStrChain(int n, vector<string> & words) {
    vector<int> dp(n,1);
    int maxi = 1;
    sort(words.begin(), words.end(), comparator);
    for(int i=1;i<n;i++) {
        for(int j=0; j<i;j++) {
            if(is_predecessor(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }
    } 
    return maxi;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> words(n,"");
        for(int i=0;i<n;i++) {
            cin >> words[i];
        }
        cout << longestStrChain(n, words) << endl;
    }
    return 0;   
}
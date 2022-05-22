/*
Problem Link: https://leetcode.com/problems/palindromic-substrings/
https://leetcode.com/problems/palindromic-substrings/discuss/2063660/Intuition-Understanding-or-Simple-code-or-Approach-1-to-Approach-2

*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string res) {
    while(i < j) {
        if(res[i] == res[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

int countSubstrings(int n, string s) {
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(isPalindrome(i,j, s)) {
                count++;
            }
        }
    }
    return count;
}

int countSubstrings2(int n, string s) {
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0;i<n;i++) {
        dp[i][i] = true;
    }
    int count = s.size();
    for(int len = 2; len<=s.size();len++) {
        for(int i=0;i<=s.size() - len;i++) {
            int j = i + len - 1;
            if(s[i] != s[j]) {
                dp[i][j] = false;
            } else {
                if(len == 2) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j]) count++;
        }
    }
    return count;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << countSubstrings(s.size(), s) << endl;
        cout << countSubstrings2(s.size(), s) << endl;
    }
    return 0;
}
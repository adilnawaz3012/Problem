/*



*/

#include<bits/stdc++.h>
using  namespace std;

bool checkComman(bitset<26> & a, bitset<26> & b) {
    for(int i=0;i<26;i++) {
        if(a[i] && b[i]) {
            return true;
        }
    }
    return false;
}

int maxProduct(int n, vector<string> & words) {
    vector<bitset<26>> chars(n);
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(auto & ch: words[i]) {
            chars[i][ch - 'a'] = 1;
        }
        for(int j=0;j<i;j++) {
            if(!checkComman(chars[i], chars[j])) {
                // ans = max(ans, int(size(chars[i]) * size(chars[j])));
                ans = max(ans, int(size(words[i]) * size(words[j])));
            }
        }
    }
    return ans;
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
        vector<string> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << maxProduct(n, nums) << endl;
    }
    return 0;
}
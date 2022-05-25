/*

*/

#include<bits/stdc++.h>
using namespace std;

bool comparator(string &s1, string & s2) {
    return s1.size() < s2.size();
}

int findMaxForm(int s, int m ,int n, vector<string> & strs) {
    sort(strs.begin(), strs.end(), comparator);
    // for(auto s: strs) {
    //     cout << s << " ";
    // }
    // cout << endl;
    int count = 0;
    for(int i=0;i<strs.size();i++) {
        int zeros = 0;
        int ones = 0;
        for(auto s: strs[i]) {
            if(s == '0') zeros++;
            else ones++;
        } 
        if((m  - zeros) >= 0 && (n - ones >= 0)) {
            count++;
            m -= zeros;
            n -= ones;
        }
    }
    return count;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int s, m, n;
        cin >> s >> m >> n;
        vector<string> strs(s);
        for(int i=0;i<s;i++) {
            cin >> strs[i];
        }
        cout << findMaxForm(s, m,n,strs) << endl;
    }
    return 0;
}
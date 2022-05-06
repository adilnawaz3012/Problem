// Remove All Adjacent Duplicates in String II

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s, int k) {
    int string_size = s.size();
    // return the same string if string size < k
    if(string_size < k) return s;
    stack<pair<char,int>> stck;
    for(int i=0;i<string_size; i++) {
        // if stack is empty || stack top element is different, push new char in stack with count 1
        if (stck.empty() || stck.top().first != s[i]) {
            stck.push({s[i], 1});
        } else {
            // takeout top element and increment its count by 1
            pair<char, int> p = stck.top();
            stck.pop();
            stck.push({s[i], p.second + 1});
        }
        // if stack top element count reached k, remove the elememt
        if (stck.top().second == k) {
            stck.pop();
        }
    }
    
    string ans = "";
    // loop through stack and pop out element
    while(!stck.empty()) {
        pair<char,int> p = stck.top();
        stck.pop();
        // add equal count of char as stored in stack
        for(int i=0;i<p.second;i++) {
            ans += p.first;
        }
    }
    // reverse the string to get string in proper order
    reverse(ans.begin(), ans.end());
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        cout << removeDuplicates(s, k) << endl;
    }
    return 0;
}
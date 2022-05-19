/*

*/

#include<bits/stdc++.h>
using namespace std;

// vector<string> to store all valure corresponding to digits
const vector<string> pad = {
     "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
};

vector<string> letterCombinations(string digits) {
    // if input string is empty , return empty vector
    if(digits.empty()) return {};
    vector<string> result;
    result.push_back("");
    // push empty string to initialize
    // loop through all the digits in input string
    for(auto digit: digits) {
        // tmp array to store current value
        vector<string> tmp;
        // loop through each char corresponding to each string digit
        for(auto candidates: pad[digit - '0']) {
            // for every char , append with result present in tmp
            for(auto s: result) {
                tmp.push_back(s + candidates);
            }
        }
        // swap tmp and result to again iterate over the process
        swap(tmp, result);
    }
    return result;
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
        vector<string> ans;
        ans = letterCombinations(s);
        for(auto a: ans) {
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}
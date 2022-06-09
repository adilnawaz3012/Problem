/*



*/

#include<bits/stdc++.h>
using  namespace std;

// Passed but bit slow
bool using_unordered_map(int n, int k, vector<int> & nums) {
    unordered_map<int, vector<int>> umap;
    for(int i=0;i<n;i++) {
        int target = nums[i];
        if(umap.find(target) != umap.end()) {
            for(auto idx: umap[target]) {
                if(abs(idx - i) <= k) {
                    return true;
                }
            }
            umap[target].push_back(i);
        } else {
            umap[target].push_back(i);
        }
    }
    return false;
}


// TLE
bool brute_force(int n, int k, vector<int> & nums) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(nums[i] == nums[j] && abs(i - j) <= k) {
                return true;
            }
        }
    }
    return false;
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
        cout << brute_force(n, k, nums) << endl;
        cout << using_unordered_map(n,k,nums) << endl;
    }
    return 0;
}
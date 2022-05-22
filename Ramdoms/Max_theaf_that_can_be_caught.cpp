/*
OPTIMIZE IT LATER

TC:

2
5 1
1 0 0 1 0
6 2
0 0 1 1 0 1

ans:
2 3
*/

#include<bits/stdc++.h>
using namespace std;

void callPolice(int idx, int k, int n, vector<int> & nums, int & count, int & canCatch) {
    if(idx < 0 || idx > n || k < 0 || canCatch == 0) {
        return;
    }
    if(k>=0 && nums[idx] == 0 && canCatch) {
        count++;
        canCatch = 0;
        nums[idx] = 2;
        return;
    }
    callPolice(idx - 1, k - 1, n, nums, count, canCatch);
    callPolice(idx + 1, k - 1, n, nums, count, canCatch);
}

int maxTheaf(int k, int n, vector<int> & nums) {
    int count = 0;
    int canCatch;
    for(int i=0;i<n;i++) {
        if(nums[i] == 1) {
            canCatch = 1;
            callPolice(i, k, n, nums, count, canCatch);
        }
    }
    return count;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n,0);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << maxTheaf(k, n, nums) << endl;
    }
    return 0;
}   
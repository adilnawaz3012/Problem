/*
Problem Link : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
Note 1: Ask if starting time is sorted or not
Note 2: Sort starting and ending time in ascending order

NOTE: if arrival is less and dep is more, means platform is busy
      if dep is less and arrival is more, it means last train already went and platform is empty and can we used again

TC:

2
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240

*/

#include<bits/stdc++.h>
using namespace std;


// TC: O(2 * nlogN) + O(2N) -> sort the 2 array + use tow pointer to tarverse the both array
// SC: O(1) -> as no extra space is used expext plot and maxi, ie constant space
int findPlatform(vector<int> & arr, vector<int> & dep, int n) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int plot = 0;
    int maxi = 0;
    int i =0, j =0;
    while(i<n && j<n) {
        if(arr[i] <= dep[j]) {
            plot++;
            i++;
            maxi = max(maxi, plot);
        } else {
            plot--;
            j++;
            maxi = max(maxi, plot);
        }
    }
    return maxi;
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
        vector<int> arr(n), dep(n);
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for(int i=0;i<n;i++) {
            cin >> dep[i];
        }
        cout << findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
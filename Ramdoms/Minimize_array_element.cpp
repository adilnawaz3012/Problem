/*


*/

#include<bits/stdc++.h>
using namespace std;

void minimizeArrayElements(int k, int n, vector<int> & nums) {
    priority_queue<int> pq;
    for(int i=0;i<n;i++) {
        pq.push(nums[i]);
    }
    while(k--) {
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();
        int p3 = p1 - p2;
        pq.push(p2);
        pq.push(p2);
        pq.push(p3);
    }
    return pq.top();
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i=0;i<n;i++) {
            cin >> nums[i];
        }
        cout << minimizeArrayElements(k,n,nums) << endl;
    }
    return 0;
}
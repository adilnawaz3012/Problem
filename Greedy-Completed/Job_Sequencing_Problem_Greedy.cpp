/*

*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    static bool comparator(struct Job m1, struct Job m2) {
        if(m1.profit > m2.profit) return true;
        return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comparator);
        vector<int> ans;
        vector<int> rooms(n,-1);
        int profit = 0;
        int jobs = 0;
        for(int i=0;i<n;i++) {
            int start = arr[i].dead;
            while(start) {
                if(rooms[start - 1] == -1) {
                    rooms[start - 1] = 0;
                    jobs++;
                    profit += arr[i].profit;
                    break;
                }
                start--;
            }
        }
        ans.push_back(jobs);
        ans.push_back(profit);
        return ans;
    } 
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {

    }
    return 0;
}
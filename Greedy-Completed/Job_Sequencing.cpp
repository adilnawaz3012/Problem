/*
Problem Link1: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
Problem Link2: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

Note 1:


*/

#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id; // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool static comparator(struct Job m1, Job m2) {
    if(m1.profit > m2.profit) return true;
    return false;
}

void JobScheduling(struct Job arr[], int n){
    sort(arr, arr + n, comparator);
    int maxJobs = 0;
    int profit = 0;
    // for(int i=0;i<n;i++) {
    //     cout << arr[i].id << " " << arr[i].dead << " " <<  arr[i].profit << endl;
    // }
    vector<int> curr(n,-1);
    for(int i=0;i<n;i++) {
        int start = arr[i].dead;
        while(start) {
            if(curr[start - 1] == -1) {
                maxJobs++;
                profit += arr[i].profit;
                curr[start - 1] = 1;
                break;
            }
            start--;
        }
    }
    cout << maxJobs << " " << profit << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        struct Job job[n];
        for(int i=0;i<n;i++) {
            int id, dead, profit;
            cin >> id >> dead >> profit;
            job[i].id = id;
            job[i].dead = dead;
            job[i].profit = profit;
        }
        JobScheduling(job, n);
    }
    return 0;
}
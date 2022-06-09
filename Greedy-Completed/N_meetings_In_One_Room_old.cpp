/*
Problem Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Note 1: Sort the array to find the meeting which takes least time so that more meeting can be scheduled.
Note 2: Sort the meeting in order of their finishing time,

NOTE: Added Solution using STRUCT , CLASS and usinf PAIRS

TC:

2
6
1 0 3 8 5 8 
2 6 4 9 7 9
3
10 12 20
20 25 30


*/


#include<bits/stdc++.h>
using namespace std;

class CustomComparator{
    public:
    bool operator() (pair<pair<int,int>, int> & p1, pair<pair<int,int>, int> & p2) {
        if(p1.first.second < p2.first.second) {
            return true;
        } else if (p1.first.second == p2.first.second) {
            return p1.second < p2.second;
        } else {
            return false;
        }
    }
};

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

class meetingClass{
    public:
    int start;
    int end;
    int pos;
};

bool comparator1(class meetingClass m1, meetingClass m2) {
    if(m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else if (m1.pos < m2.pos) return true;
    return false;
}

void maxMeetingsClass(vector<int> & start, vector<int> & end, int n) {
    meetingClass meet[n];
    for(int i=0;i<n;i++) {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator1);
    vector<int> answer;
    int limit = meet[0].end;
    answer.push_back(meet[0].pos);
    for(int i=1; i<n; i++) {
        if(limit < meet[i].start) {
            answer.push_back(meet[i].pos);
            limit = meet[i].end;
        }
    }
    for(int i=0;i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}


// TC: O(n) + O(nLogN) + O(n) -> Putting in DS + Sorting it later + Traversin it again
// SC: O(n) -> To Store all elements in DS
void maxMeetings(vector<int> & start, vector<int> & end, int n) {
    struct meeting meet[n];
    for(int i=0;i<n;i++) {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator);
    vector<int> answer;
    int limit = meet[0].end;
    answer.push_back(meet[0].pos);
    for(int i=1; i<n; i++) {
        if(limit < meet[i].start) {
            answer.push_back(meet[i].pos);
            limit = meet[i].end;
        }
    }
    for(int i=0;i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void maxMeetingsPair(vector<int> & start, vector<int> & end, int n) {
    vector<pair<pair<int,int>, int>> p;
    for(int i=0;i<n;i++) {
        pair<int, int> temp = {start[i] , end[i]};
        p.push_back({temp, i+1});
    }
    sort(p.begin(), p.end(), CustomComparator());
    vector<int> answer;
    int limit = p[0].first.second;
    answer.push_back(p[0].second);
    for(int i=1; i<n; i++) {
        if(limit < p[i].first.first) {
            answer.push_back(p[i].second);
            limit = p[i].first.second;
        }
    }
    for(int i=0;i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
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
        vector<int> start(n), end(n);
        for(int i=0;i<n;i++){
            cin >> start[i];
        }
        for(int i=0;i<n;i++) {
            cin >> end[i];
        }
        maxMeetings(start, end, n);
        maxMeetingsClass(start, end, n);
        maxMeetingsPair(start, end, n);
    }
    return 0;
}
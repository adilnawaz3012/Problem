#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, int m, vector<vector<char>> & farm) {
    if(i <0 || j <0 || i == n || j == m) {
        return INT_MAX;
    }
    
    int top = solve(i-1, j, n, m, farm);
    int down = solve(i+1, j, n, m, farm);
    int left = solve(i, j - 1, n, m, farm);
    int right = solve(i , j+1, n, m, farm);
    return min({top, down, left, right});
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> farm(n, vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> farm[i][j];
        }
    }
    cout << solve(0,0,n,m,farm);
    return 0;
}
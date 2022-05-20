/*

Problem lIknk: https://leetcode.com/problems/unique-paths-ii/

Self explanatory

*/

#include<bits/stdc++.h>
using namespace std;

int helper(int i, int j, int m, int n, vector<vector<int>> & obstacleGrid,  vector<vector<int>> & ds) {
    if(i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1) {
        return 0;
    }
    if(i == m -1 && j == n-1) {
        return 1;
    }
    if(ds[i][j] != -1) return ds[i][j];
    return ds[i][j] = helper(i+1, j, m , n , obstacleGrid, ds) + helper(i,j+1, m, n, obstacleGrid, ds);
}

int DynamicProgramming(vector<vector<int>> & grid) {
    int m = obstacleGrid.size();
        int n = m > 0 ? obstacleGrid[0].size() : 0;
        // vector<vector<int>> ds(m, vector<int>(n,-1));
        vector<vector<int>> dp(m, vector<int>(n,0));
        // return helper(0,0,m,n, obstacleGrid, ds);
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
               if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
               } else {
                    int up = 0;
                    int left = 0;
                    if(i > 0) {
                        up = dp[i-1][j];
                    }
                    if(j>0) {
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m ,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin >> grid[i][j];
            }
        }
        cout << uniquePathsII(grid) << endl;
    }
    return 0;
}
/*
Problem link : https://leetcode.com/problems/unique-paths-iii/

First, we find our startig point (i1, j1) and count the number of empty cells. We then do DFS,
marking visited elements and tracking number of steps (s). If we reach the target, 
and number of steps matches the number of empty cells (s == t_s) - we found a path.

Better Explanation : https://leetcode.com/problems/unique-paths-iii/discuss/221941/C%2B%2B-brute-force-DFS
*/

#include<bits/stdc++.h>
using namespace std;

// empty = 1 to handle starting case, grid[i][j] == 1 case


int dfs(vector<vector<int>>& g, int i, int j, int s, int t_s) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1) return 0;
  if (g[i][j] == 2) return s == t_s ? 1 : 0;
  g[i][j] = -1;
  int paths = dfs(g, i + 1, j, s + 1, t_s) + dfs(g, i - 1, j, s + 1, t_s) +
    dfs(g, i, j + 1, s + 1, t_s) + dfs(g, i, j - 1, s + 1, t_s);
  g[i][j] = 0;
  return paths;
}
int uniquePathsIII(vector<vector<int>>& g) {
  auto i1 = 0, j1 = 0, t_steps = 0;
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[0].size(); ++j) {
      if (g[i][j] == 1) i1 = i, j1 = j;
      if (g[i][j] != -1) ++t_steps;
    }
  return dfs(g, i1, j1, 1, t_steps);
}

int empty = 1, res=0;
void helper(int i, int j, int m, int n, vector<vector<int>> & grid, int count) {
    if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j]  == -1) {
        return;
    } 
    if(grid[i][j] == 2) {
        if(empty == count) res++;
        return;
    }
    grid[i][j] = -1;
    helper(i -1, j, m, n , grid, count + 1);
    helper(i+1, j, m, n, grid, count + 1);
    helper(i, j-1, m, n, grid, count + 1);
    helper(i, j +1, m, n, grid, count + 1);
    grid[i][j] = 0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = m > 0 ? grid[0].size() : 0;
    int x, y;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(grid[i][j] == 1) {
                x = i;
                y = j;
            } else if(grid[i][j] == 0) {
                empty++;
            }
        }
    }
    helper(x,y,m,n,grid, 0);
    return res;
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
        cout << uniquePathsIII(grid) << endl;
    }
    return 0;
}
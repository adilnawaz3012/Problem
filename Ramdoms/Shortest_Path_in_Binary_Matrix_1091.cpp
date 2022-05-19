/*
Similar like n-queens problem
*/

#include<bits/stdc++.h>
using namespace std;

// Helper function to check if point is in grid
bool isValidPoint(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<=n && y<=m;
};

int shortestPathBinaryMatrix(vector<vector<int>> & grid, int n){
    if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) {
        return -1;
    }
    vector<int> x_points = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> y_points = {-1, 0, 1, -1, 1, -1, 0 ,1};

    int n = grid.size();
    int m = grid.size() > 0 ? grid[0].size() : 0;
    queue<vector<int>> q;
    vector<int> curr;
    q.push()
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
        vector<vector<int>> grid(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                cin >> grid[i][j];
            }
        }
        cout << shortestPathBinaryMatrix(grid, n) << endl;
    }
    return 0;
}
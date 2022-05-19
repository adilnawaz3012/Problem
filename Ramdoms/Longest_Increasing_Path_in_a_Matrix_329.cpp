/*
TC:

3
3 3
9 9 4
6 6 8
2 1 1
3 3
3 4 5
3 2 6
2 2 1
1 1 
1

*/

#include<bits/stdc++.h>
using namespace std;

int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; 

int recursion(int i, int j, int m, int n, vector<vector<int>> & matrix) {
    int MAX = 1;
    for(int k=0;k<4;k++) {
        // calculate the new index where we'll move
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        // check boundary cases
        // check is new element at new index is greater than current element or not
        if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j]) {
            continue;
        }
        // if greater, then add 1 and call method again with new index formed
        MAX = max(MAX, 1 + recursion(new_i, new_j, m, n, matrix));
    }
    return MAX;
}

int memoization(int i, int j, int m, int n, vector<vector<int>> & matrix, vector<vector<int>> & ds) {
    int MAX = 1;
    for(int k=0;k<4;k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || matrix[new_i][new_j] <= matrix[i][j]) {
            continue;
        }
        if(ds[i][j] != -1) return ds[i][j]; 
        MAX = max(MAX, 1 + memoization(new_i, new_j, m, n, matrix, ds));
    }
    return ds[i][j] = MAX;
}

int longestIncreasingPath(vector<vector<int>> & matrix) {
    int m = matrix.size();
    int n = m > 0 ? matrix[0].size() : 0;
    int maxi = 1;
    vector<vector<int>> ds(m, vector<int>(n,-1));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            // maxi = max(maxi, recursion(i,j,m,n, matrix));
            maxi = max(maxi, memoization(i,j,m,n,matrix, ds));
        }
    }
    return maxi;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m , vector<int>(n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin >> matrix[i][j];
            }
        }
        cout << longestIncreasingPath(matrix) << endl;
    }
    return 0;
}
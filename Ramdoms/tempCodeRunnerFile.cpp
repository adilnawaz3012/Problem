    return 0;
    // }
    // if(prev < matrix[i][j]) {
    //     prev = matrix[i][j];
    //     return 1;
    // } else {
    //     return 0;
    // }
    // int left = dfs(i-1, j, m, n, prev, matrix);
    // int right = dfs(i + 1, j, m, n, prev, matrix);
    // int up = dfs(i, j - 1, m, n, prev, matrix);
    // int down = dfs(i, j + 1, m, n, prev, matrix);
    // return 1 + max(left , max(right , max(up, down)));
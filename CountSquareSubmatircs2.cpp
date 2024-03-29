TC = O(n^2)
SC = O(1) ;

int solve(vector<vector<int>>& mat) {
    int ans = 0;

    int row = mat.size() - 1;
    int col = mat[0].size() - 1;

    for (int i = col; i >= 0; i--) ans += mat[row][i];

    for (int i = row - 1; i >= 0; i--) ans += mat[i][col];

    for (int r = row - 1; r >= 0; r--) {
        for (int c = col - 1; c >= 0; c--) {
            int right = mat[r][c + 1];
            int down = mat[r + 1][c];
            int downright = mat[r + 1][c + 1];
            if (mat[r][c] == 1) {
                mat[r][c] += min(downright, min(right, down));
                ans += mat[r][c];
            }
        }
    }
    return ans;
}
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, int dr[], int dc[]) {
        vis[row][col] = 1;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < 4; ++i) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
                dfs(nrow, ncol, mat, vis, dr, dc);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; ++j) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis, dr, dc);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis, dr, dc);
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis, dr, dc);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis, dr, dc);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
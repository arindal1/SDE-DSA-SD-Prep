class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& vis, int drow[], int dcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                dfs(nrow, ncol, mat, vis, drow, dcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;

        int m = grid[0].size();
        if (m == 0) return 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int j = 0; j < m; ++j) {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, grid, vis, drow, dcol);

            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
                dfs(n - 1, j, grid, vis, drow, dcol);
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, grid, vis, drow, dcol);

            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                dfs(i, m - 1, grid, vis, drow, dcol);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 1)
                    res++;
            }
        }

        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        int val = matrix[row][col];
        if (val == target)
            return true;
        else if (val < target)
            ++row;
        else
            --col;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    cout << (searchMatrix(matrix, target) ? "true" : "false") << "\n";
    return 0;
}

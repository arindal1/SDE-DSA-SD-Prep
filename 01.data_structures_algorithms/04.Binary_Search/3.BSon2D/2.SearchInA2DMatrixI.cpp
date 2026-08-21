#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size();
    if (m == 0) return false;

    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        int val = matrix[row][col];

        if (val == target)
            return true;
        else if (val < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, target;
    cin >> n >> m >> target;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << (searchMatrix(matrix, target) ? "true" : "false") << "\n";
    return 0;
}

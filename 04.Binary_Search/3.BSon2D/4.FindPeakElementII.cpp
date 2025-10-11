#include <bits/stdc++.h>
using namespace std;

int maxElementRow(const vector<vector<int>>& mat, int c) {
    int n = mat.size(), idx = 0;
    for (int i = 1; i < n; ++i)
        if (mat[i][c] > mat[idx][c])
            idx = i;
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = maxElementRow(mat, mid);

        int leftVal  = (mid > 0)       ? mat[r][mid-1] : INT_MIN;
        int rightVal = (mid < m - 1)   ? mat[r][mid+1] : INT_MIN;
        int curVal   = mat[r][mid];

        if (curVal > leftVal && curVal > rightVal) {
            return {r, mid};
        } else if (curVal < leftVal) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {-1, -1};  // fallback
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    auto peak = findPeakGrid(mat);
    cout << peak[0] << " " << peak[1] << "\n";
    return 0;
}

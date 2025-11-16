#include <bits/stdc++.h>
using namespace std;

/*
  findCelebrity:
  Input: n x n matrix mat where mat[i][j] == 1 means i knows j.
  Output: index of celebrity (0..n-1) or -1 if none.
*/
int findCelebrity(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return -1;
    for (const auto &row : mat) if ((int)row.size() != n) return -1;

    int i = 0, j = n - 1;
    while (i < j) {
        if (mat[i][j] == 1) {
            ++i;
        } else {
            --j;
        }
    }

    int cand = i;

    for (int k = 0; k < n; ++k) {
        if (k == cand) continue;
        if (mat[cand][k] == 1) return -1;
        if (mat[k][cand] == 0) return -1;
    }

    return cand;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0}
    };

    cout << "The celebrity: " << findCelebrity(mat) << endl;
    return 0;
}

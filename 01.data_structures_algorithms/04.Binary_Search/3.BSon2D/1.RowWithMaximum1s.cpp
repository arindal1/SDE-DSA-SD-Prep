#include <bits/stdc++.h>

using namespace std;

int countOnes(vector<int> arr, int m, int k) {
    int low = 0, high = m-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= k)
            high = mid - 1;
        else low = mid + 1;
    }

    return m - low;
}

int maximumOnes(vector<vector<int>> matrix, int n, int m) {
    int maxCnt = 0, index = -1;

    for (int i = 0; i < n; i++) {
        int cnt = countOnes(matrix[i], m, 1);

        if (cnt > maxCnt) {
            maxCnt = cnt;
            index = i;
        }
    }

    return index;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << maximumOnes(matrix, n, m);
    return 0;
}
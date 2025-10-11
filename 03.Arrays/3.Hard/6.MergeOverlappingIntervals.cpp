#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> overlappingIntervals(vector<vector<int>> arr, int n) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    ans = overlappingIntervals(arr, n);

    for (int i = 0; i < ans.size(); i++) {
        for (auto j : ans[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}





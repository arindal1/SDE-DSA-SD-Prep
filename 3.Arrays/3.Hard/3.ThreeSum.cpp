#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> arr, int n) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1])
            continue;
        int j = i+1;
        int k = n-1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j-1])
                    j++;
                while (j < k && arr[k] == arr[k+1])
                    k--;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ans = threeSum(arr, n);

    for (int i = 0; i < ans.size(); i++) {
        for (auto j : ans[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
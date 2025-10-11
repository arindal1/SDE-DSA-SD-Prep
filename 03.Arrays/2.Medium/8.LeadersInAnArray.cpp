#include <bits/stdc++.h>

using namespace std;

vector<int> Leaders(vector<int>& arr, int n) {
    int maxi = INT_MIN;
    vector<int> res;

    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > maxi)
            res.push_back(arr[i]);
        maxi = max(maxi, arr[i]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = Leaders(arr, n);

    for (auto i : res)
        cout << i << " ";
    return 0;
}

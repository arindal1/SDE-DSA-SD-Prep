#include<bits/stdc++.h>

using namespace std;

int XorK(vector<int> arr, int n, int target) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        xr = xr^arr[i];
        int x = xr^target;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << XorK(arr, n, target);

    return 0;
}





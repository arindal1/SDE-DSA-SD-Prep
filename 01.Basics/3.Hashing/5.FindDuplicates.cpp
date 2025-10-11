#include <bits/stdc++.h>
using namespace std;

bool hasDuplicates(vector<int> &arr, int n) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        if (mpp[arr[i]] > 1)
            return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (hasDuplicates(arr, n) ? "Yes" : "No") << endl;
    return 0;
}

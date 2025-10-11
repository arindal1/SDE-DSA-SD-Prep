#include <bits/stdc++.h>

using namespace std;

int Consecutive(vector<int> &arr, int n) {
    int maxi = 0, ctr = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ctr++;
            maxi = max(maxi, ctr);
        } else
            ctr = 0;
    }
    return maxi;
}

int main() {
    int n, num;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Consecutive(arr, n);
    return 0;
}

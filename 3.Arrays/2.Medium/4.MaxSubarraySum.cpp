#include <bits/stdc++.h>

using namespace std;

int Kadane(vector<int>& arr, int n) {
    int sum = 0, maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];

        if (sum > maxi)
            maxi = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Kadane(arr, n);
    return 0;
}

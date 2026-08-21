#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(const vector<int>& arr, double D) {
    int cnt = 0, n = arr.size();
    for (int i = 1; i < n; ++i) {
        cnt += int((arr[i] - arr[i-1]) / D);
    }
    return cnt;
}

double minimiseMaxDistance(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    double low = 0.0, high = 0.0;
    // upper bound = largest existing gap
    for (int i = 1; i < n; ++i)
        high = max(high, double(arr[i] - arr[i-1]));

    const double eps = 1e-6;
    while (high - low > eps) {
        double mid = (low + high) / 2.0;
        if (numberOfGasStationsRequired(arr, mid) > k)
            low = mid;   // too many needed → D too small
        else
            high = mid;  // feasible → try smaller D
    }
    return high;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    double result = minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << result << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatingMissing(const vector<int>& arr, int n) {
    long long S = 0, P = 0;
    for (int x : arr) {
        S += x;
        P += (long long)x * x;
    }

    long long N   = n;
    long long S_N = N * (N + 1) / 2;
    long long P_N = N * (N + 1) * (2*N + 1) / 6;

    long long diff = S - S_N;
    long long sum  = (P - P_N) / diff;

    long long r = (diff + sum) / 2;
    long long m = r - diff;

    return {(int)r, (int)m};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    auto result = repeatingMissing(arr, n);
    cout << result[0] << " " << result[1] << "\n";
    return 0;
}

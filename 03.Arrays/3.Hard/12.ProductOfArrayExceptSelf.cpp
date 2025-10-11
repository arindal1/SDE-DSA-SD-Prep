#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n == 0) return {};

    vector<int> output(n);
    output[0] = 1;
    for (int i = 1; i < n; ++i) {
        output[i] = output[i-1] * nums[i-1];
    }
    long long right = 1;
    for (int i = n - 1; i >= 0; --i) {
        long long val = static_cast<long long>(output[i]) * right;
        if (val > numeric_limits<int>::max()) val = numeric_limits<int>::max();
        if (val < numeric_limits<int>::min()) val = numeric_limits<int>::min();
        output[i] = static_cast<int>(val);

        right *= nums[i];
    }
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4};
    auto out = productExceptSelf(arr);
    for (int x : out) cout << x << " ";
    cout << "\n";

    // Example: reading from input (uncomment if needed)
    // int n; cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; ++i) cin >> a[i];
    // auto res = productExceptSelf(a);
    // for (int x : res) cout << x << ' ';
    // cout << '\n';
    return 0;
}

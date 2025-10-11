#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    for (int i = n - 1; i >= 0 && carry; --i) {
        int val = digits[i] + carry;
        digits[i] = val % 10;
        carry = val / 10;
    }
    if (carry) {
        digits.assign(n + 1, 0);
        digits[0] = 1;
    }

    return digits;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans;
    ans = plusOne(arr);
    
    for (auto i : ans)
        cout << i << " ";
}

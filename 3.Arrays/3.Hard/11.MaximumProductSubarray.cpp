#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &arr, int n) {
    int pre = 1, suf = 1, ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        
        pre = pre * arr[i];
        suf = suf * arr[n-i-1];
        ans = max(ans, max(pre, suf));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumProduct(arr, n);

    return 0;
}


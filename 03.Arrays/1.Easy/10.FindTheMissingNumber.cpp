#include <bits/stdc++.h>

using namespace std;

int Missing(vector<int> &arr, int n) {
    int xor1 = 0, xor2 = 0, N = n-1;

    for (int i = 0; i < N; i++) {
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^n;
    return xor1^xor2;

}

int main() {
    int n, num;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Missing(arr, n);
    return 0;
}

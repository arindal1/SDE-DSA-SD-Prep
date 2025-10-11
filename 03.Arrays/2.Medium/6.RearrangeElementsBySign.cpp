#include <bits/stdc++.h>

using namespace std;

vector<int> Rearrange(vector<int>& arr, int n) {
    int pos = 0, neg = 1;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            res[neg] = arr[i];
            neg += 2;
        } else {
            res[pos] = arr[i];
            pos += 2;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = Rearrange(arr, n);

    for (auto i : res)
        cout << i << " ";
    return 0;
}

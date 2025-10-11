#include <bits/stdc++.h>

using namespace std;

vector<int> RotateArray(vector<int> &arr, int n) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return arr;

    for (int i = j+1; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    RotateArray(arr, n);

    for (auto i : arr)
        cout << i << " ";

    return 0;
}

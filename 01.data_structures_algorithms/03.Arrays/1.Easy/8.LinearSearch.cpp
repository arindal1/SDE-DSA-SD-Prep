#include <bits/stdc++.h>

using namespace std;

int Search(vector<int> &arr, int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

int main() {
    int n, num;
    cin >> n >> num;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Search(arr, n, num);
    return 0;
}

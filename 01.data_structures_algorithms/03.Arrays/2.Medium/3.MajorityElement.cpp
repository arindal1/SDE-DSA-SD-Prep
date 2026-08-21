#include <bits/stdc++.h>

using namespace std;

int MajorityElement(vector<int>& arr, int n) {
    int el = 0, ctr1 = 0, ctr2 = 0;

    for (int i = 0; i < n; i++) {
        if (ctr1 == 0) {
            ctr1 = 1;
            el = arr[i];
        } else if (arr[i] == el)
            ctr1 ++;
        else ctr1 --;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == el)
            ctr2 ++;
    }
    if (ctr2 > n/2)
        return el;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << MajorityElement(arr, n);
    return 0;
}

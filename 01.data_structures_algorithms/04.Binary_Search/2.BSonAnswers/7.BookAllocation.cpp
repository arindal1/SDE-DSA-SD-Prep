#include <bits/stdc++.h>
using namespace std;

int countStudents(const vector<int>& arr, int L) {
    int students = 1;
    long long pages = 0;
    for (int x : arr) {
        if (pages + x <= L)
            pages += x;
        else {
            students++;
            pages = x;
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low  = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countStudents(arr, mid) <= m)
            high = mid - 1;  // mid is feasible
        else
            low = mid + 1;   // mid too small
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findPages(arr, n, m) << "\n";
    return 0;
}

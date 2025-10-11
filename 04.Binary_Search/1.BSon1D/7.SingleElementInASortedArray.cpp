#include <bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }
        bool pairOnLeft  = (mid % 2 == 1 && arr[mid] == arr[mid-1]);
        bool pairOnRight = (mid % 2 == 0 && arr[mid] == arr[mid+1]);
        if (pairOnLeft || pairOnRight) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Should not reach here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << singleNonDuplicate(arr) << "\n";
    return 0;
}

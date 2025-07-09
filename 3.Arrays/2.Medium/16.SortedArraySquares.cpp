#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<int> nums1(m + n), nums2(n);

    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> nums2[j];
    }

    merge(nums1, m, nums2, n);

    for (int x : nums1) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
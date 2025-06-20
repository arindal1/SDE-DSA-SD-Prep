#include<bits/stdc++.h>

using namespace std;

int subArray(vector<int> &nums, int n, long long k) {
    int left = 0, right = 0, maxLen = 0;
    long long sum = nums[0];
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
        right++;
        if (right < n)
            sum += nums[right];
    }
    return maxLen;
}

int main () {
    int n;
    cin >> n;
    long long k;
    cin >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << subArray(nums, n, k);
    return 0;
}
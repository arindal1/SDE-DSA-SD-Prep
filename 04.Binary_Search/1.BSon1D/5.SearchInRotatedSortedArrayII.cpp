#include <bits/stdc++.h>
using namespace std;


bool search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        // When low, mid, and high are equal, we cannot decide; shrink window
        if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
            low++;
            high--;
        }
        // Left half is sorted
        else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool found = search(nums, target);
    cout << (found ? "true" : "false") << "\n";
    return 0;
}

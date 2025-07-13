#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int low = 0, high = nums.size() - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else {
                idx = mid;
                if (isSearchingLeft)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return idx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    vector<int> ans = sol.searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}

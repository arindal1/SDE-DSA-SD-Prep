class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), ind = 0;

        if (n == 1)
            return true;

        for (int i = 0; i < n; ++i) {
            if (i > ind) {
                return false;
            }
            if (ind == n - 1)
                return true;

            ind = max(ind, i + nums[i]);
        }

        return true;
    }
};
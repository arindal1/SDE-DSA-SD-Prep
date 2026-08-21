class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findLessThanEqual(nums, goal) - findLessThanEqual(nums, goal - 1);
    }

    int findLessThanEqual(vector<int> &nums, int goal) {
        if (goal < 0) return 0;

        int l = 0, r = 0, count = 0, sum = 0, n = nums.size();

        while (r < n) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l ++;
            }
            count += r - l + 1;
            r ++;
        }
        return count;
    }
};

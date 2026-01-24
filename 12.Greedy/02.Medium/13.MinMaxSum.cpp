class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;

        int maxSum = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];

            maxSum = max(sum, maxSum);
            l ++;
            r --;
        }

        return maxSum;
    }
};
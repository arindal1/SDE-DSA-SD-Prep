class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostNice(nums, k) - atMostNice(nums, k - 1);
    }

    int atMostNice(vector<int> &nums, int k) {
        int l = 0, r = 0, count = 0, numOdd = 0;
        int n = nums.size();

        while (r < n) {
            numOdd += (nums[r] % 2);

            while (numOdd > k) {
                numOdd -= (nums[l] % 2);
                l ++;
            }
            count += r - l + 1;
            r ++;
        }
        return count;
    }
};
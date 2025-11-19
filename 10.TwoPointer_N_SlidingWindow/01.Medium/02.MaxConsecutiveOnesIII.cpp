class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0, maxL = 0, len = 0;

        while (r < n) {
            int x = nums[r];
            if (x == 0)
                cnt++;
            
            if (cnt > k) {
                if (nums[l] == 0)
                    cnt --;
                l ++;
            }
            
            maxL = max(maxL, (r + 1) - l);
            r ++;
        }

        return maxL;
    }
};
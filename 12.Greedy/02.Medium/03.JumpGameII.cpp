class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, jumps = 0;

        while (r < n - 1) {
            int farthest = r;

            for (int i = l; i <= r; ++i) {
                long long reach = (long long)i + nums[i];
                farthest = max(farthest, (int)min(reach, (long long)n - 1));
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};
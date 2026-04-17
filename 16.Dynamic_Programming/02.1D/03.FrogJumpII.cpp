class Solution {
public:
    int frogJump(int n, vector<int>& h, int k) {
        vector<int> dp(n, 0);

        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int ans = INT_MAX;

            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int cost = dp[i - j] + abs(h[i] - h[i - j]);
                    ans = min(ans, cost);
                }
            }

            dp[i] = ans;
        }

        return dp[n - 1];
    }
};
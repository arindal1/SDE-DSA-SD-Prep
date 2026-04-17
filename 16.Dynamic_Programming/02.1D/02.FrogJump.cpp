class Solution {
  private:
    int solve(int i, vector<int>& h, vector<int>& dp) {
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int one = solve(i - 1, h, dp) + abs(h[i] - h[i - 1]);

        int two = INT_MAX;
        if (i > 1)
            two = solve(i - 2, h, dp) + abs(h[i] - h[i - 2]);

        return dp[i] = min(one, two);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp);
    }
};

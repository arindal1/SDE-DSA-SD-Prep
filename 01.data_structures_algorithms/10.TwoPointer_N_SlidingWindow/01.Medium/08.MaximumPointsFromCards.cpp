class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totSum = 0, lSum = 0, rSum = 0, n = cardPoints.size();

        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }
        totSum = lSum;
        int l = n - 1;
        for (int j = k - 1; j >= 0; --j) {
            lSum -= cardPoints[j];
            rSum += cardPoints[l];
            --l;

            totSum = max(totSum, (lSum + rSum));
        }

        return totSum;
    }
};
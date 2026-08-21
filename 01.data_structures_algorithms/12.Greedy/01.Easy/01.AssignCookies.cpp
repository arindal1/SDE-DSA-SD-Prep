class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size(), cnt = 0;
        int l = 0, r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (l < n && r < m) {
            if (s[r] >= g[l]) {
                l++;
                r++;
                cnt++;
            } else {
                r++;
            }
        }

        return cnt;
    }
};
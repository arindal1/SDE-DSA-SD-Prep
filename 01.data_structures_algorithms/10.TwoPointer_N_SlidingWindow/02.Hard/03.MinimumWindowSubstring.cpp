class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        
        if (n < m)
            return "";
        
        int l = 0, r = 0, cnt = 0;
        int minLen = INT_MAX, sInd = -1;
        string res = "";
        vector<int> hash(256, 0);

        for (int i = 0; i < m; ++i) {
            hash[(unsigned char)t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sInd = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }
};
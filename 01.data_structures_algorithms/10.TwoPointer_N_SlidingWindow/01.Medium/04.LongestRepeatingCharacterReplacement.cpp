class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, r = 0, maxLen = 0, maxFreq = 0, n = s.size(), changes = 0;

        while (r < n) {
            freq[s[r] - 'A'] ++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A'] --;
                l ++;
            }
            maxLen = max(maxLen, (r - l + 1));
            r ++;
        }
        return maxLen;
    }
};
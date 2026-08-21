class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0, n = s.size();
        vector<int> freq(3, 0);
        int left = 0, right = 0;

        while (right < n) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += n - right;

                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        
        return count;
    }
};
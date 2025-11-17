int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        if (s.size() == 1)
            return 1;

        vector<int> hash(256, -1);
        int left = 0, right = 0, n = s.size();
        int maxLen = 0, len = 0;

        while (right < n) {
            if (hash[s[right]] != -1) {
                if (hash[s[right]] >= left)
                    left = hash[s[right]] + 1;
            }

            len = (right + 1) - left;
            maxLen = max(maxLen, len);

            hash[s[right]] = right;
            right ++;
        }
        return maxLen;
}

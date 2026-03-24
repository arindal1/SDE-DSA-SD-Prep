class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;
    unordered_map<string, int> level;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];

            string originalWord = word;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    word[i] = c;

                    if (st.count(word)) {
                        if (!level.count(word)) {
                            level[word] = currLevel + 1;
                            q.push(word);
                            parents[word].push_back(originalWord);
                        } 
                        else if (level[word] == currLevel + 1) {
                            parents[word].push_back(originalWord);
                        }
                    }
                }
                word[i] = original;
            }
        }

        if (!level.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};
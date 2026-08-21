class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        parenthesis("", 0, 0, n, res);
        return res;
    }

    void parenthesis(string curr, int open, int close, int n, vector<string>& res) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n)
            parenthesis(curr + '(', open+1, close, n, res);
        if (close < open)
            parenthesis(curr + ')', open, close+1, n, res);
    }
};




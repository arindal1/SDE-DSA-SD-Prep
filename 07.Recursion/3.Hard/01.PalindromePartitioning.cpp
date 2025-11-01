vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> ds;

    palindromes(0, s, ds, res);
    return res;
}

void palindromes(int ind, string s, vector<string> &ds, vector<vector<string>> &res) {
    if (ind == s.size()) {
        res.push_back(ds);
        return;
    }
    for (int i = ind; i < s.length(); i++) {
        if (isPalin(s, ind, i)) {
            ds.push_back(s.substr(ind, i - ind + 1));
            palindromes(i + 1, s, ds, res);
            ds.pop_back();
        }
    }
}
    
bool isPalin(string &s, int low, int high) {
    while (low <= high) {
        if (s[low] != s[high]) {
            return false;
        }
        low ++;
        high --;
    }
    return true;
}
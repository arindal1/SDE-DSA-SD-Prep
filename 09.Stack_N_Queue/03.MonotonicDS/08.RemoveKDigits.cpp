string removeKdigits(string num, int k) {
    stack<char> st;
    int n = num.size();

    for (auto ch : num) {
        while (!st.empty() && st.top() > ch && k > 0) {
            st.pop();
            k--;
        }
        st.push(ch);
    }

    while (!st.empty() && k > 0) {
        st.pop();
        k--;
    }

    if (st.empty())
        return "0";

    string res = "";
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
        
    reverse(res.begin(), res.end());
       
    int i = 0;
    while (i < res.size() && res[i] == '0') {
        i++;
    }
    res = res.substr(i);
    return res.empty() ? "0" : res;
}

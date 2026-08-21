class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char cur : s) {
            if (!st.empty()) {
                char last = st.top();
                if (isPair(last, cur)) {
                    st.pop();
                    continue;
                }
            }
            st.push(cur);
        }

        return st.empty();        
    }

private:
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};    
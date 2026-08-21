class MinStack {
public:
    std::stack<long long> st;
    long long mini;

    MinStack() : mini(LLONG_MAX) {}

    void push(int v) {
        long long val = v;
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long el = st.top();
        st.pop();

        if (el < mini) {
            mini = 2LL * mini - el;
        }
        if (st.empty()) {
            mini = LLONG_MAX;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long el = st.top();
        if (el < mini) {
            return static_cast<int>(mini);
        }
        return static_cast<int>(el);
    }

    int getMin() {
        if (st.empty()) return -1;
        return static_cast<int>(mini);
    }
};

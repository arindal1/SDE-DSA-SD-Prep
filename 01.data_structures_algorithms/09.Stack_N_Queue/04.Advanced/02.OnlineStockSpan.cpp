class StockSpanner {
private:
    stack<pair<int, int>> st;
    int ind = -1;
public:
    StockSpanner() {
        ind = -1;
        st = stack<pair<int, int>>();
        // while (!st.empty()) st.pop();
    }
    
    int next(int price) {
        ind++;
        int ans;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        
        ans = ind - ((st.empty()) ? -1 : st.top().second);
        st.push({price, ind});

        return ans;
    }
};

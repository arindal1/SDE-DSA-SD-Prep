vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans (n);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (i < n) {
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i % n]);
    }
    return ans;
}

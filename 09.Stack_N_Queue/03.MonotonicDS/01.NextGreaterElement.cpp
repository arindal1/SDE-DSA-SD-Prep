vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int i = (int)nums2.size() - 1; i >= 0; --i) {
            int x = nums2[i];
            while (!st.empty() && st.top() <= x)
                st.pop();
            nextGreater[x] = st.empty() ? -1 : st.top();
            st.push(x);
        }

    vector<int> ans;
    ans.reserve(nums1.size());
    for (int v : nums1)
        ans.push_back(nextGreater[v]);
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> mat(m, vector<int>(n));

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += (matrix[i][j]) - '0';
            if (matrix[i][j] == '0') {
                mat[i][j] = 0;
                sum = 0;
            }
            mat[i][j] = sum;
        }
    }
        
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        int area = prefixHisto(mat[i]);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int prefixHisto(vector<int>& arr) {
    stack<int> st;
    int maxArea = 0, n = arr.size();

    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxArea = max(maxArea, width * height);
        }
        st.push(i);
    }
    return maxArea;
}

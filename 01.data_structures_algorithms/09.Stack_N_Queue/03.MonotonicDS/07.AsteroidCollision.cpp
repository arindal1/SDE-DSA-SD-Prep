vector<int> asteroidCollision(vector<int>& arr) {
    vector<int> ans;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 0) {
            ans.push_back(arr[i]);
        } else {
            while (!ans.empty() && ans.back() > 0 && abs(arr[i]) > ans.back()) {
                ans.pop_back();
            }

            if (!ans.empty() && ans.back() == abs(arr[i]))
                ans.pop_back();
            else if (ans.empty() || ans.back() < 0)
                ans.push_back(arr[i]);
        }
    }
    return ans;
}
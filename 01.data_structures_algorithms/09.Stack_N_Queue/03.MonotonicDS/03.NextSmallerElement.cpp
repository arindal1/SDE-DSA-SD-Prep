#include<bits/stdc++.h>

using namespace std;

vector<int> nextSmallerElement(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size());

        for (int i = (int)arr.size() - 1; i >= 0; --i) {
            int x = arr[i];
            while (!st.empty() && st.top() >= x)
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(x);
        }
    return ans;
}

int main() {
    vector<int> v;
    string line;
    
    getline(cin, line);

    stringstream ss(line);
    int num;
    while (ss >> num)
        v.push_back(num);

    vector<int> ans = nextSmallerElement(v);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}
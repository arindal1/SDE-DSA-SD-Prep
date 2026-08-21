#include <bits/stdc++.h>

using namespace std;

int LongestSequence(vector<int>& arr, int n) {
    int longest = 1;
    if (n == 0) return 0;

    unordered_set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(arr[i]);
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << LongestSequence(arr, n);
    return 0;
}

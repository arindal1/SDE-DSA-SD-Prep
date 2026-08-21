#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestJob(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        int totTime = 0, waitTime = 0;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; ++i) {
            waitTime += totTime;
            totTime += arr[i];
        }

        return waitTime / n;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 1, 4, 2, 5},
        {8, 4, 3, 1, 2},
        {5},
        {},
        {7, 7, 7, 7},
        {10, 1, 10, 1}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        
        // Print input
        cout << "Input = [";
        for (int j = 0; j < testCases[i].size(); j++) {
            cout << testCases[i][j];
            if (j + 1 < testCases[i].size()) cout << ", ";
        }
        cout << "]";

        // Compute Output
        int result = sol.shortestJob(testCases[i]);
        cout << "  Output = " << result << endl;
    }

    return 0;
}

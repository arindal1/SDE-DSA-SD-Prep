#include <bits/stdc++.h>

using namespace std;

vector<int> TwoSum(vector<int>& nums, int n, int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = TwoSum(arr, n, target);

    if (result.empty()) {
        cout << "No valid pair found\n";
    } else {
        for (int i : result)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;


void moveZeroes(vector<int>& nums) {
        int i = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    sol.moveZeroes(nums);

    for (int x : nums)
        cout << x << " ";
    cout << "\n";

    return 0;
}
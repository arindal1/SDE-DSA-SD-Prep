#include<bits/stdc++.h>

using namespace std;

int AppearsOnce(vector<int> &nums, int n) {
    int x = 0;
    for (int i = 0; i < nums.size(); i++) {
        x = x^nums[i];
    }
    return x;
}

int main () {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << AppearsOnce(nums, n);
    return 0;
}
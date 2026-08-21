#include <bits/stdc++.h>
using namespace std;

int removeVal(vector<int>& nums, int val) {
    int i = 0, j = (int)nums.size() - 1;
    while (i <= j) {
        if (nums[i] == val) {
            nums[i] = nums[j];
            j--;
        } else {
            i++;
        }
    }
    return i;
}

int main() {
    int n, val;
    cin >> n >> val;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k = removeVal(arr, val);
    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << arr[i] << (i+1<k ? ' ' : '\n');

    return 0;
}

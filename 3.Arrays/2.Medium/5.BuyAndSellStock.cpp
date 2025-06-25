#include <bits/stdc++.h>

using namespace std;

int MaxProfit(vector<int>& arr, int n) {
    int mini = arr[0], profit = 0, cost = 0;

    for (int i = 1; i < n; i++) {
        cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(arr[i], mini);
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << MaxProfit(arr, n);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int findDays(const vector<int>& weights, int cap) {
    int days = 1, load = 0;
    for (int w : weights) {
        if (load + w > cap) {
            days++;
            load = w;
        } else {
            load += w;
        }
    }
    return days;
}

int leastWeightCapacity(vector<int>& weights, int D) {
    int low  = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (findDays(weights, mid) <= D) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, D;
    cin >> n >> D;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << leastWeightCapacity(weights, D) << "\n";
    return 0;
}

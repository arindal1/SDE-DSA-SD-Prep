#include <bits/stdc++.h>
using namespace std;

vector<int> sumCombi(vector<int> &arr1, vector<int> &arr2, int k) {
    if (arr1.empty() || arr2.empty() || k <= 0) return {};

    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end(), greater<int>());

    priority_queue<tuple<int, int, int>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push(make_tuple(arr1[0] + arr2[0], 0, 0));
    visited.insert({0, 0});

    vector<int> result;

    while (k-- && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();

        int sum = get<0>(top);
        int i   = get<1>(top);
        int j   = get<2>(top);

        result.push_back(sum);

        if (i + 1 < (int)arr1.size() && !visited.count({i + 1, j})) {
            maxHeap.push(make_tuple(arr1[i + 1] + arr2[j], i + 1, j));
            visited.insert({i + 1, j});
        }

        if (j + 1 < (int)arr2.size() && !visited.count({i, j + 1})) {
            maxHeap.push(make_tuple(arr1[i] + arr2[j + 1], i, j + 1));
            visited.insert({i, j + 1});
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {3, 4, 5};
    vector<int> arr2 = {2, 6, 3};
    int k = 2;

    vector<int> res = sumCombi(arr1, arr2, k);

    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

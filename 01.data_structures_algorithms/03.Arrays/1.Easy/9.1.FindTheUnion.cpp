#include <bits/stdc++.h>

using namespace std;

vector<int> UnionSorted(const vector<int>& arr1, const vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0;
    vector<int> res;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            if (res.empty() || res.back() != arr1[i])
                res.push_back(arr1[i]);
            i++;
        } else {
            if (res.empty() || res.back() != arr2[j])
                res.push_back(arr2[j]);
            j++;
        }
    }

    while (j < n2) {
        if (res.empty() || res.back() != arr2[j])
            res.push_back(arr2[j]);
        j++;
    }
    while (i < n1) {
        if (res.empty() || res.back() != arr1[i])
            res.push_back(arr1[i]);
        i++;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    for (int j = 0; j < n2; j++) cin >> arr2[j];

    vector<int> uni = UnionSorted(arr1, arr2);

    for (int x : uni) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}

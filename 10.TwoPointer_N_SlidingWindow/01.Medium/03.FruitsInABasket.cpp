#include <bits/stdc++.h>

using namespace std;

int maxFruits(vector<int> &fruits, int n, int k) {
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> basket;

    while (r < n) {
        basket[fruits[r]]++;

        while (basket.size() > k) {
            basket[fruits[l]] --;
            if (basket[fruits[l]] == 0)
                basket.erase(fruits[l]);
            l ++;
        }

        maxLen = max(maxLen, r - l + 1);
        r ++;
    }
    return maxLen;
}

int main() {
    vector<int> fruits = {1, 2, 3, 2, 2};
    int n = 5, k = 2;

    cout << maxFruits(fruits, n, k) << endl;
    return 0;
}
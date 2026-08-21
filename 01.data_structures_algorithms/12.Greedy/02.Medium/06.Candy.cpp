#include<bits/stdc++.h>

using namespace std;

int numCandies(vector<int> &ratings) {
    int n = ratings.size(), candy = n, i = 1;

    while (i < n) {
        if (ratings[i] == ratings[i - 1]) {
            i++;
            continue;
        }

        int peak = 0;
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            i++;
            candy += peak;
        }

        int valley = 0;
        while (i < n && ratings[i] < ratings[i - 1]) {
            valley++;
            i++;
            candy += valley;
        }

        candy -= min(peak, valley);
    }

    return candy;
}

int main() {
    vector<int> ratings = {1, 2, 2};

    cout << numCandies(ratings);
    return 0;
}
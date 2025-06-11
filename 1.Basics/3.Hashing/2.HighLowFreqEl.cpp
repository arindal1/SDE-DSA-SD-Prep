#include <bits/stdc++.h>
using namespace std;

void HighLowFreq(vector<int> arr) {
    unordered_map<int, int> mpp;

    for (int i : arr)
        mpp[i]++;

    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int high = -1, low = -1;

    for (auto i : mpp) {
        if (i.second > maxFreq) {
            maxFreq = i.second;
            high = i.first;
        }
        if (i.second < minFreq) {
            minFreq = i.second;
            low = i.first;
        }
    }

    cout << "Highest frequency element: " << high << endl;
    cout << "Lowest frequency element: " << low << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 5, 7, 8};

    HighLowFreq(arr);

    return 0;
}
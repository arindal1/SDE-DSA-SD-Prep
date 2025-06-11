#include<bits/stdc++.h>

using namespace std;

void ElFreq(vector<int> arr) {
    unordered_map<int, int> mpp;
    for (int i : arr)
        mpp[i]++;
    for (auto i : mpp)
        cout << i.first << " - " << i.second << endl;
}

int main() {
    vector<int> arr = {2, 3, 1, 1, 2, 4};

    ElFreq(arr);
    return 0;
}
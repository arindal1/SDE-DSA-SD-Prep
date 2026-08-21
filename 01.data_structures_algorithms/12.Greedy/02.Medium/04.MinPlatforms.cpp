#include<bits/stdc++.h>
using namespace std;

int numStations(vector<int> &arr, vector<int> &dep) {
    int n = arr.size(), stations = 1, result = 1;
    int i = 1, j = 0;

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            stations++;
            i++;
        } else {
            stations--;
            j++;
        }
        result = max(result, stations);
    }

    return result;
}

int main() {
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};

    cout << numStations(arr, dep);
}
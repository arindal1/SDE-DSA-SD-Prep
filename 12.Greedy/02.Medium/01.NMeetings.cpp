#include <bits/stdc++.h>
using namespace std;

vector<int> meetings(vector<int> &start, vector<int> &end, int n) {
    vector<tuple<int, int, int>> meeting;

    for (int i = 0; i < n; ++i) {
        meeting.push_back({end[i], start[i], i+1});
    }

    sort(meeting.begin(), meeting.end());
    vector<int> result;
    int lastEnd = -1;

    for (auto& m : meeting) {
        int e = get<0>(m);
        int s = get<1>(m);
        int ind = get<2>(m);

        if (s > lastEnd) {
            result.push_back(ind);
            lastEnd = e;
        }
    }

    return result;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 5, 7, 9, 9};

    vector<int> res = meetings(start, end, N);

    for (auto i : res) {
        cout << i << " ";
    }

    return 0;
}
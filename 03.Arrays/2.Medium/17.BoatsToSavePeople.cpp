#include <bits/stdc++.h>
using namespace std;


int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1, boats = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else {
                right--;
            }
            boats++;
        }
        return boats;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, limit;
    cin >> n >> limit;
    vector<int> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    Solution sol;
    cout << sol.numRescueBoats(people, limit) << "\n";
    return 0;
}
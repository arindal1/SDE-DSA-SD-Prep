#include <bits/stdc++.h>

using namespace std;

int coinChange(int V) {
    vector<int> notes = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = notes.size(), cnt = 0, remain = 0, i = n - 1;
    int val = V;

    while (i >= 0 && val > 0) {
        if (notes[i] <= val) {
            val -= notes[i];
            cnt++;
        } else {
            --i;
        }
    }

    return cnt;
}

int main() {
    int V = 121;
    
    cout << coinChange(V);
    return 0;
}
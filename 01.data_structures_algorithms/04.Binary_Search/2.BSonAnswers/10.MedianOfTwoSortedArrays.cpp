#include <bits/stdc++.h>
using namespace std;

double medianOfTwoSorted(const vector<int>& a, const vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2) 
        return medianOfTwoSorted(b, a);

    int total = n1 + n2, half = (total + 1) / 2;
    int low = 0, high = n1;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = half - i;

        int l1 = (i > 0)     ? a[i - 1] : INT_MIN;
        int r1 = (i < n1)    ? a[i]     : INT_MAX;
        int l2 = (j > 0)     ? b[j - 1] : INT_MIN;
        int r2 = (j < n2)    ? b[j]     : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            if (total % 2)
                return double(max(l1, l2));
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
    return 0.0; // Should never reach here
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);

    for (int i = 0; i < n1; i++) 
        cin >> a[i];
    for (int i = 0; i < n2; i++) 
        cin >> b[i];

    double ans = medianOfTwoSorted(a, b);
    if (ans == int(ans)) 
        cout << int(ans) << "\n";
    else 
        cout << fixed << setprecision(1) << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

int main() {
    // Example 1
    cout << "Example 1:" << endl;
    vector<int> nums1 = {1, 2, 3, 4};
    KthLargest kth1(3, nums1);
    cout << kth1.add(5) << endl;  // 3
    cout << kth1.add(2) << endl;  // 3
    cout << kth1.add(7) << endl;  // 4

    // Example 2
    cout << "\nExample 2:" << endl;
    vector<int> nums2 = {5, 5, 5, 5};
    KthLargest kth2(2, nums2);
    cout << kth2.add(2) << endl;  // 5
    cout << kth2.add(6) << endl;  // 5
    cout << kth2.add(60) << endl; // 6

    return 0;
}

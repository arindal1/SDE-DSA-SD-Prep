#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

long long connectSticks(const vector<long long> &arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq(
        arr.begin(), arr.end()
    );

    long long res = 0;

    while (pq.size() > 1) {
        long long st1 = pq.top(); pq.pop();
        long long st2 = pq.top(); pq.pop();

        long long sum = st1 + st2;
        res += sum;
        pq.push(sum);
    }

    return res;
}

struct TestCase {
    string name;
    vector<long long> sticks;
    long long expected;
};

void runTests() {
    vector<TestCase> tests = {
        {
            "Example: {1, 8, 3, 5}",
            {1, 8, 3, 5},
            30 // Explanation: (1+3)=4, cost=4; (4+5)=9, cost=13; (9+8)=17, total=30
        },
        {
            "Empty array",
            {},
            0
        },
        {
            "Single stick",
            {10},
            0
        },
        {
            "Two sticks",
            {2, 4},
            6 // 2+4
        },
        {
            "All equal sticks",
            {5, 5, 5, 5},
            // Steps: (5+5)=10 (cost 10), (5+5)=10 (cost 20), (10+10)=20 (cost 40)
            40
        },
        {
            "Increasing sequence",
            {1, 2, 3, 4, 5},
            // Steps:
            // (1+2)=3 cost=3; heap: [3,3,4,5]
            // (3+3)=6 cost=9; heap: [4,5,6]
            // (4+5)=9 cost=18; heap: [6,9]
            // (6+9)=15 cost=33
            33
        },
        {
            "Large values",
            {1000000000LL, 1000000000LL, 1000000000LL},
            // (1e9+1e9)=2e9 cost=2e9
            // (2e9+1e9)=3e9 cost=5e9
            5000000000LL
        }
    };

    cout << "Running test cases...\n\n";

    int passed = 0;
    for (const auto &tc : tests) {
        long long result = connectSticks(tc.sticks);
        bool ok = (result == tc.expected);

        cout << tc.name << " -> ";
        if (ok) {
            cout << "PASSED";
            passed++;
        } else {
            cout << "FAILED";
        }
        cout << " (Expected: " << tc.expected << ", Got: " << result << ")\n";
    }

    cout << "\nSummary: " << passed << " / " << tests.size() << " tests passed.\n\n";
}

int main() {
    // 1. Run built-in tests
    runTests();

    // 2. Allow user to try custom input
    cout << "---- Manual Test ----\n";
    cout << "Enter number of sticks (n), then n stick lengths.\n";
    cout << "Example:\n5\n1 8 3 5 2\n\n";

    int n;
    if (!(cin >> n)) {
        cout << "No valid input for n. Exiting.\n";
        return 0;
    }

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long cost = connectSticks(arr);
    cout << "Minimum cost to connect all sticks = " << cost << "\n";

    return 0;
}

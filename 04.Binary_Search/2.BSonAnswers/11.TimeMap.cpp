#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() = default;

    // Store value for key at given timestamp.
    // Assumes (for best performance) that set calls for a given key come
    // with non-decreasing timestamps (so we can push_back).
    void set(const string &key, const string &value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }

    // Return value with largest timestamp <= query timestamp, or "" if none.
    string get(const string &key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";

        const auto &arr = it->second;
        int low = 0, high = static_cast<int>(arr.size()) - 1;
        string res = "";

        // Binary search for the rightmost pair with arr[mid].first <= timestamp
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid].first <= timestamp) {
                res = arr[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TimeMap tm;
    string cmd;

    cout << "Commands:\n  set <key> <value> <timestamp>\n  get <key> <timestamp>\n";
    cout << "Example:\n  set foo bar 1\n  get foo 1\n\n";

    // Read commands until EOF
    while (cin >> cmd) {
        if (cmd == "set") {
            string key, value;
            int timestamp;
            if (!(cin >> key >> value >> timestamp)) break;
            tm.set(key, value, timestamp);
            cout << "ok\n";
        } else if (cmd == "get") {
            string key;
            int timestamp;
            if (!(cin >> key >> timestamp)) break;
            string ans = tm.get(key, timestamp);
            if (ans.empty()) cout << "(empty)\n";
            else cout << ans << '\n';
        } else {
            // Unknown command — print help and continue
            cout << "Unknown command. Use 'set' or 'get'.\n";
            // optionally consume rest of line
            string rest;
            getline(cin, rest);
        }
    }

    return 0;
}

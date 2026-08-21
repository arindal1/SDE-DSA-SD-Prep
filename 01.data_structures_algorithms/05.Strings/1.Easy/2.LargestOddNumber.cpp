#include <bits/stdc++.h>
using namespace std;


string largestOddNumber(string num) {
        int n = num.size();
        
        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            int digit = num[i] - '0';
            if (digit % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        
        // No odd digit found
        return "";
}


int main() {
    Solution sol;
    string num;

    cin >> num;

    string result = sol.largestOddNumber(num);
    
    if (result.empty()) {
        cout << " " << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}

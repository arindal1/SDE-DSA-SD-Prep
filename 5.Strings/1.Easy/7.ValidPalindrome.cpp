#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left]))
            left++;
        while (left < right && !isalnum(s[right]))
            right--;
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    cout << isPalindrome(s);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

bool isPalindromeRecursive(const string& s, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (s[left] != s[right]) {
        return false;
    }
    return isPalindromeRecursive(s, left + 1, right - 1);
}

bool isPalindrome(const string& s) {
    return isPalindromeRecursive(s, 0, static_cast<int>(s.length()) - 1);
}

int main() {
    string s;
    getline(cin, s);

    if (isPalindrome(s)) {
        cout << '"' << s << "\" is a palindrome.\n";
    } else {
        cout << '"' << s << "\" is not a palindrome.\n";
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int romanToInt(const string &s) {
    int val[256] = {0};
    val['I']=1; val['V']=5; val['X']=10; val['L']=50;
    val['C']=100; val['D']=500; val['M']=1000;

    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(toupper(s[i]));
        int curr = val[c];
        if (curr == 0) return -1;            // invalid character
        int next = (i + 1 < s.size()) ? val[static_cast<unsigned char>(toupper(s[i+1]))] : 0;
        result += (curr < next) ? -curr : curr;
    }
    return result;
}

int main() {
    string s;
    if (!(cin >> s)) return 0;               // read a single token
    int ans = romanToInt(s);
    if (ans < 0) cout << "Invalid Roman numeral\n";
    else cout << ans << '\n';
    return 0;
}

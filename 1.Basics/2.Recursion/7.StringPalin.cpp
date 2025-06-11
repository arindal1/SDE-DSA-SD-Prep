#include <stdio>
#include <string>

using namespace std;

boolean pal(string str, int i, int j) {
    if (i >= j)
        return true;
    if (str[i] != str[j])
        return false;
    rev(arr, i++, j--);
}

int main () {
    string str = "RACECAR"
    int i = 0, j = 6;
    rev(arr, i, j);
}
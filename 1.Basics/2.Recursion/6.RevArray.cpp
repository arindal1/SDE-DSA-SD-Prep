#include <stdio.h>

using namespace std;

<vector> rev(<vector> arr, int i, int j) {
    if (i >= j)
        return arr;
    swap(arr[i], arr[j]);
    rev(arr, i++, j--);
}

int main () {
    <vector> arr = [1, 2, 3, 4, 5];
    int i = 0, j = 4;
    rev(arr, i, j);
}
#include <iostream>
using namespace std;

void printReverse(int arr[], int n) {
    if (n <= 0) {
        return;
    }
    cout << arr[n - 1] << ' ';
    printReverse(arr, n - 1);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    printReverse(arr, n);
    cout << endl;

    delete[] arr;
    return 0;
}

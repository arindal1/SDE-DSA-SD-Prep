#include<bits/stdc++.h>

using namespace std;

void LargestElement(vector<int> &arr, int n) {
    int largest = arr[0], second_largest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest =  arr[i];
        }
    }
    cout << second_largest << " - " << largest;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    LargestElement(arr, n);

    return 0;
}
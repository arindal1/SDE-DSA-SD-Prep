#include<bits/stdc++.h>

using namespace std;

void RemoveDuplicates(vector<int> &arr, int n) {
    int i = 0;
    
    for (int j = 0; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout << i + 1 << endl;
    for (int j = 0; j <= i; j++)
        cout << arr[j] << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    RemoveDuplicates(arr, n);

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i <= n-2; i++) {
        int min = i;
        for (int j = i; j <= n-1; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

int main() {
    int arr[] = {3, 6, 12, 9, 1};
    int n = 5;

    SelectionSort(arr, n);
    for ( auto i : arr)
        cout << i << " ";
    return 0;
}
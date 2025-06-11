void printNto1(int n) {
    if (n <= 0) {
        return;            // Base case: stop when n ≤ 0
    }
    cout << n << '\n';
    printNto1(n - 1);
}
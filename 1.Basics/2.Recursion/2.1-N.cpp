void printFirstN(int n) {
    if (n <= 0) {
        return;
    }
    printFirstN(n - 1);
    cout << n << '\n';
}
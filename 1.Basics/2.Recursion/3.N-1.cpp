int num(n) {
    if (n == 1) {
        return 1;
    }
    cout << n;
    num (--n);
}
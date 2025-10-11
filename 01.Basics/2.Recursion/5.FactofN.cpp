long long factorial(int n) {
    if (n <= 1) {
        return 1LL;
    }
    return n * factorial(n - 1);
}
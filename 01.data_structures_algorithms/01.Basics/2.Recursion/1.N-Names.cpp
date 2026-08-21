void printName(int n) {
    if (n <= 0) {
        return;
    }

    cout << "name" << '\n';
    printName(n - 1);
}
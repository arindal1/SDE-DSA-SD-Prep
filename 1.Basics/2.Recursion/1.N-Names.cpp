int name(n){
    if (n == 0) {
        return 0;
    }
    cout << "name";
    name(n--);
}
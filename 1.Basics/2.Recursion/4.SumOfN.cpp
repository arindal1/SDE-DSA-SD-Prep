int sum (i, sum) {
    if (i < 1) {
        return sum;
    }
    sum (i-1, sum+i);
}
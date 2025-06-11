n, fact;
int fact (i, fac) {
    if (i < 1)
        return fact;
    fact (i-1, fact*i);
}
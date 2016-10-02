int Solution::gcd(int a, int b) {
    int tmp;
    if(a < b) swap(a,b);
    while(b != 0) {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

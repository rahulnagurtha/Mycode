int Solution::reverse(int A) {
    long long int ans = 0;
    bool negative = (A < 0  ? true : false);
    A = abs(A);
    while(A > 0) {
        ans = ans*10 + A%10;
        A = A/10;
    }
    if(negative) ans = ans*-1;
    if(ans > INT_MAX || ans < INT_MIN) return 0;
    return (int)(ans);
}
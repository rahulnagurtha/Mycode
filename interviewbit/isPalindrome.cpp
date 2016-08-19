bool Solution::isPalindrome(int A) {
    long long int rev = 0,original = A;
    if(A < 0) return false;
    while(A > 0) {
        rev = rev*10 + A%10;
        A = A/10;
    }
    return (rev == original);
}
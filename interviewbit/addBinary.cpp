string Solution::addBinary(string A, string B) {
    string ans;
    int maxlen = max(A.size(),B.size());
    while(A.size() < maxlen) {
        A = '0' + A;
    }
    while(B.size() < maxlen) {
        B = '0' + B;
    }
    int carry = 0;
    int sum;
    for (int i = B.size() - 1; i >= 0; --i) {
        sum = 0;
        sum = carry + (A[i] - '0') + (B[i] - '0');
        if(sum == 0) {
            ans = '0' + ans;
            carry = 0;
        }
        else if(sum == 1) {
            ans = '1' + ans;
            carry = 0;
        }
        else if(sum == 2) {
            ans = '0' + ans;
            carry = 1;
        }
        else {
            ans = '1' + ans;
            carry = 1;
        }
    }
    if(carry != 0) ans = '1' + ans;
    return ans;
}
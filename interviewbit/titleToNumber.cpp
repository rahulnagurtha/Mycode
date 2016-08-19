int Solution::titleToNumber(string A) {
    int wt = 1;
    int ans = 0;
    for(int i = A.size()-1;i >= 0;i--) {
        ans += (A[i] - 'A' + 1)*(wt);
        wt *= 26;
    }
    return ans;
}
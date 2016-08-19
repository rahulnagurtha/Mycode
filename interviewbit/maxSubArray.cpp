int Solution::maxSubArray(const vector<int> &A) {
    int ans = INT_MIN;
    int last = INT_MIN;
    for(int i = 0 ;i < A.size();i++) {
        last = (last < 0 ? A[i] : last + A[i]);
        ans = max(ans,last);
    }
    return ans;
}

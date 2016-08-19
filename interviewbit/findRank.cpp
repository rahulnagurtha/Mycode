int Solution::findRank(string A) {
    int fact[55];
    int ans = 1;
    fact[0] = 0;
    fact[1] = 1;
    for(int i = 2; i < 55;i++) {
        fact[i] = (fact[i-1]*i)%1000003;
    }
    for(int i = 0;i < A.size(); i++) {
        int cnt = 0;
        for (int j = i+1; j < A.size(); ++j) {
            if(A[i] > A[j]) cnt++;
        }
        ans = (ans + cnt*fact[A.size()-1-i])%1000003;
    }
    return ans;
}
int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    int cnt[2][33] = {0};
    int cur;
    int bitCount;
    long long int tmp = 1;
    for(int i = 0;i < A.size();i++) {
        cur = A[i];
        bitCount = 0;
        while(cur > 0) {
            cnt[cur%2][bitCount]++;
            cur = cur >> 1;
            bitCount++;
        }
    }
    for(int i = 0;i < 33;i++) {
        if(cnt[1][i] % 3 == 1) {
            ans += (int)tmp;
        }
        tmp = tmp << 1;
    }
    return ans;
}

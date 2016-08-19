int Solution::trailingZeroes(int A) {
    int numZeroes = 0,numFives = 0;
    for(int i = 1;i <= A; i++) {
        int cur = i;
        while(cur % 2 == 0) {
            cur /= 2;
            numZeroes++;
        }
        while(cur % 5 == 0) {
            cur /= 5;
            numFives++;
        }
    }
    return min(numZeroes,numFives);
}

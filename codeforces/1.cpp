int MAX(int one,int two) {
	if(one > two) return one;
	else return two;
}

int Solution::lis(const vector<int> &A) {
    int dp[100005] = {0};
    for (int i = 0; i < A.size(); ++i) {
    	dp[i] = 1;
    	int tmp = 0;
    	for (int j = 0; j < i; ++j) {
    		if(A[j] < A[i]) tmp = MAX(tmp,dp[j]);	
	    }
	    dp[i] += tmp;
    }
    int tmp = 0;
    for (int i = 0; i < A.size(); ++i) {
    	tmp = MAX(dp[i],tmp);
    }
    return tmp;
}

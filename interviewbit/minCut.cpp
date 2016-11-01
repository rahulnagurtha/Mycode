int Solution::minCut(string A) {
    bool isPalindrome[A.size()+5][A.size()+5];
    int dp[A.size()+5];
    for (int len = 1; len <= A.size(); ++len) {
    	for (int lft = 0; lft + len <= A.size(); ++lft) {
    		isPalindrome[lft][lft+len-1] = ((A[lft] == A[lft+len-1]) && 
    										(len <= 2 ? true : isPalindrome[lft+1][lft+len-2]));
    	}
    }
    dp[A.size()] = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
    	dp[i] = INT_MAX;
    	for (int j = i; j < A.size(); ++j) {
    		if(isPalindrome[i][j]) dp[i] = min(dp[i],1 + dp[j+1]);
    	}
    }
    return dp[0]-1;
}
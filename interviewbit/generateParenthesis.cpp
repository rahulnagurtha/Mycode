vector<vector<string> > dp;

vector<string> Solution::generateParenthesis(int A) {
    dp.clear();
    vector<string> tmp;
    tmp.push_back("");
    dp.push_back(tmp);
    for (int i = 2; i <= 2*A; i += 2) {
    	vector<string> tmp;
    	for (int j = 0; j < i; j += 2) {
    		int k = i - j;
    		//within is j,outside is k
    		for (int l = 0; l < dp[j].size(); ++l) {
    			for (int r = 0; r < dp[k].size(); ++r) {
    				string cur;
    				cur += '(';
    				cur += dp[j][l];
    				cur += ')';
    				cur += dp[k][r];
    				dp[i/2].push_back(cur);
    			}
    		}
    	}
    	dp.push_back(tmp);
    }
    return dp[A/2];
}
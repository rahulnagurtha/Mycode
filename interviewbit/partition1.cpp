vector<vector<string> > ans;


void recurse(int pos,string &A,vector<vector<bool> > &isPalindrome,vector<string> &ansSoFar) {
	if(pos == A.size()) {
		ans.push_back(ansSoFar);
		return;
	}
	for (int i = pos; i < A.size(); ++i) {
		if(isPalindrome[pos][i]) {
			ansSoFar.push_back(A.substr(pos,pos-i+1));
			recurse(i+1);
			ansSoFar.pop_back();
		}
	}
}

vector<vector<string> > Solution::partition(string A) {
	ans.clear();
	vector<bool> tmp[A.size() + 5];
	vector<vector<bool> > isPalindrome;
	for (int i = 0; i < A.size()+5; ++i) {
		isPalindrome.push_back(tmp);
	}
	memset(isPalindrome,true,sizeof(isPalindrome));
	for (int len = 1; len <= A.size(); ++len) {
		for (int i = 0; i + len <= A.size(); ++i) {
			isPalindrome[i][i+len-1] = ((A[i] == A[i+len-1]) && isPalindrome[i+1][max(i+len-2,0)]);
		}
	}
	recurse(0,A,isPalindrome,ansSoFar);
	return ans;
}
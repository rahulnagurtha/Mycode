vector<int> Solution::prevSmaller(vector<int> &A) {
	vector<int> ans;
	stack<int> S;
	for (int i = 0; i < A.size(); ++i) {
		ans.push_back(-1);
	}
	for (int i = A.size() - 1; i >= 0; --i) {
		while(!S.empty() && A[S.top()] > A[i]) {
			ans[S.top()] = A[i];
			S.pop();
		}
		S.push(i);
	}
	return ans;
}

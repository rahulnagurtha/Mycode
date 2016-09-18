vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
	deque<int> Q;
	vector<int> ans;
	for (int i = 0; i < B; ++i) {
		while(!Q.empty() && A[Q.back()] <= A[i]) Q.pop_back();
		Q.push_back(i);
	}
	ans.push_back(A[Q.front()]);
	if(B >= A.size()) {
		return ans;
	}
	for (int i = B; i < A.size(); ++i) {
		while(!Q.empty() && A[Q.back()] <= A[i]) Q.pop_back();
		Q.push_back(i);
		while(!Q.empty() && Q.front() <= i - B) Q.pop_front();
		ans.push_back(A[Q.front()]);
	}
	return ans;
}
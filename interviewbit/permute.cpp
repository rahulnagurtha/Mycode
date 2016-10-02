typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI ans;

void go(int start, VI &A) {
	if(start == A.size() - 1) {
		ans.push_back(A);
		return;
	}
	for (int i = start; i < A.size(); ++i) {
		swap(A[start],A[i]);
		go(start + 1 , A);
		swap(A[start],A[i]);
	}
	return;
}

VOVI Solution::permute(VI &A) {
	ans.clear();
	go(0,A);
	return ans;
}
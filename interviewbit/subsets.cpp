typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI ans;


void go(int start, VI &A, VI &tmp) {
    assert(start < A.size());
	if(start == A.size() - 1) {
		tmp.push_back(A[start]);
		ans.push_back(tmp);
		tmp.pop_back();
		if(tmp.size() != 0) ans.push_back(tmp);
		return; 
	}
	tmp.push_back(A[start]);
	go(start + 1, A, tmp);
	tmp.pop_back();
	go(start + 1, A, tmp);
	return;
}

VOVI Solution::subsets(vector<int> &A) {
    ans.clear();
    sort(A.begin(),A.end());
	VI tmp;
    ans.push_back(tmp);
    if(A.size() != 0) go(0,A,tmp);
    sort(ans.begin(),ans.end());
    return ans;
}
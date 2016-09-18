typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI result;
VI current;

void recurse(int target,VI &A,int cur) {
	int cnt = 0;
	if(target == 0) {
		result.push_back(current);
		return;
	}
	if(target < 0 || cur >= A.size()) return;
	recurse(target,A,cur+1);
	current.push_back(A[cur]);
	recurse(target-A[cur],A,cur);
	current.pop_back();
	return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    result.clear();
    current.clear();
    sort(A.begin(),A.end());
    VI uniq;
    uniq.push_back(A[0]);
    for (int i = 1; i < A.size(); ++i) {
    	if(uniq.back() != A[i]) uniq.push_back(A[i]);
    }
    recurse(B,uniq,0);
    sort(result.begin(),result.end());
    return result;
}
typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI result;
VI current;
map<int,int> cnt;

void recurse(int target,VI &A,int cur) {
	if(target == 0) {
		result.push_back(current);
		return;
	}
	if(target < 0 || cur >= A.size()) return;
	int curCount = cnt[A[cur]];
	int toRemove = 0;
	for (int i = 0; i <= curCount; ++i) {
		if(i > 0) {
			toRemove++;
			current.push_back(A[cur]);
		}
		recurse( target - i*A[cur], A, cur + 1);
	}
	while(toRemove > 0) {
		current.pop_back();
		toRemove--;
	}
	return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    result.clear();
    current.clear();
    cnt.clear();
    sort(A.begin(),A.end());
    VI uniq;
    uniq.push_back(A[0]);
    cnt[A[0]]++;
    for (int i = 1; i < A.size(); ++i) {
    	cnt[A[i]]++;
    	if(uniq.back() != A[i]) uniq.push_back(A[i]);
    }
    recurse(B,uniq,0);
    sort(result.begin(),result.end());
    return result;
}
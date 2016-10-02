typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI result;
VI current;
map<int,int> cnt;

void recurse(VI &A,int cur) {
	if(cur >= A.size()) {
		result.push_back(current);
		return;
	}
	int curCount = cnt[A[cur]];
	int toRemove = 0;
	for (int i = 0; i <= curCount; ++i) {
		if(i > 0) {
			toRemove++;
			current.push_back(A[cur]);
		}
		recurse(A, cur + 1);
	}
	while(toRemove > 0) {
		current.pop_back();
		toRemove--;
	}
	return;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    result.clear();
    current.clear();
    cnt.clear();
    if(A.size() == 0) {
        result.push_back(current);
        return result;
    }
    sort(A.begin(),A.end());
    VI uniq;
    uniq.push_back(A[0]);
    cnt[A[0]]++;
    for (int i = 1; i < A.size(); ++i) {
    	cnt[A[i]]++;
    	if(uniq.back() != A[i]) uniq.push_back(A[i]);
    }
    recurse(uniq,0);
    sort(result.begin(),result.end());
    return result;
}
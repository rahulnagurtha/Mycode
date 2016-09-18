typedef vector<int> VI;
typedef vector<VI> VOVI;

VOVI result;
VI current;

void generate(int rem,int from,int till) {
	if(rem == 0) {
		result.push_back(current);
		return;
	}
	if(from > till) return;
	//this is the least
	current.push_back(from);
	generate(rem - 1,from+1,till);
	current.pop_back();
	//this is not the least
	generate(rem,from+1,till);
}

vector<vector<int> > Solution::combine(int n, int k) {
    result.clear();
    current.clear();
    generate(k,1,n);
    sort(result.begin(),result.end());
    return result;
}
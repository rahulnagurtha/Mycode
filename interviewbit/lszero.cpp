vector<int> Solution::lszero(vector<int> &A) {
	unordered_map<int,int> data;
	int sum = 0;
	int lenSoFar = 0;
	int l,r;
	vector<int> ans;
	data[0] = -1;
	for (int i = 0; i < A.size(); ++i) {
		sum += A[i];
		if(data.find(-1*sum) != data.end() && lenSoFar < (i - data[-1*sum])) {
			lenSoFar = i - data[-1*sum];
			l = data[-1*sum];
			r = i;
		}
		if(data.find(sum) == data.end()) data[sum] = i;
	}
	for (int i = l; i <= r; ++i) {
		ans.push_back(A[i]);
	}
	return ans;
}
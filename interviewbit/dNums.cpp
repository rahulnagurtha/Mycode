vector<int> Solution::dNums(vector<int> &A, int B) {
	vector<int> ans;
	map<int,int> data;
	for (int i = 0; i < B - 1; ++i) {
		data[A[i]]++;
	}
	for (int lft = 0,ryt = B - 1; ryt < A.size(); ++lft,++ryt) {
		data[A[ryt]]++;
		ans.push_back(data.size());
		data[A[lft]]--;
		if(data[A[lft]] == 0) data.erase(A[lft]);
	}
	return ans;
}
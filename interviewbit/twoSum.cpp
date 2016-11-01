vector<int> Solution::twoSum(const vector<int> &A, int B) {
	unordered_map<int,int> data;
	vector<int> ans;
	for (int i = 0; i < A.size(); ++i) {
		int other = B - A[i];
		if(data.find(other) != data.end()) {
			ans.push_back(data[other]);
			ans.push_back(i + 1);
			break;
		}
		if(data.find(A[i]) == data.end()) {
			data[A[i]] = i + 1;
		}
	}
	return ans;
}
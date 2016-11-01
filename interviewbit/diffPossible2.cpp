int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> data;
	for (int i = 0; i < A.size(); ++i) {
		int other = A[i] - B; //A[i] - A[j] = B
		if(data.find(other) != data.end()) {
			return 1;
		}
		other = B + A[i];
		if(data.find(other) != data.end()) {
			return 1;
		}
		data.insert(A[i]);
	}
	return 0;
}
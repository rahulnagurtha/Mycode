int Solution::trap(const vector<int> &A) {
	vector<int> nextLargest(A.size() + 1);
	vector<int> largestIdx(A.size() + 1);
	stack<int> T;
	int ans = 0;
	//calculate next greatest
	// T.push(0);
	for (int i = 0; i < A.size(); ++i) {
		if(T.size() == 0) T.push(i);
		else {
			while(!T.empty() && A[T.top()] <= A[i]) {
				nextLargest[T.top()] = i;
				T.pop();
			}
			T.push(i);
		}
	}
	while(!T.empty()) {
		nextLargest[T.top()] = -1;
		T.pop();
	}
	//complete
	int highestIdx = A.size() - 1;
	for (int i = A.size() - 2; i >= 0; --i) {
		largestIdx[i] = highestIdx;
		if(A[i] > A[highestIdx]) highestIdx = i;
	}
	//start
	int curPos = 0;
	while(curPos < A.size() - 1) {
		if(nextLargest[curPos] != -1) { //nextGreater exits
			for (int i = curPos; i <= nextLargest[curPos]; ++i) {
				ans += max(0,A[curPos] - A[i]);
			}
			curPos = nextLargest[curPos];
		}
		else { //nextGreater doesnt exits
			for (int i = curPos; i <= largestIdx[curPos]; ++i) {
				ans += max(0,A[largestIdx[curPos]] - A[i]);
			}
			curPos = largestIdx[curPos];
		}
		// assert();
	}
	return ans;
}
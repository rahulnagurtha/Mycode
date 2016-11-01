int Solution::canJump(vector<int> &A) {
    bool isPossible[A.size() + 5];
    isPossible[A.size() - 1] = true;
    for (int i = A.size() - 2; i >= 0; --i) {
    	isPossible[i] = false;
    	for (int j = i + 1; j < A.size() && j <= i + A[i]; ++j) {
    		if(isPossible[j]) isPossible[i] = true;
    		if(isPossible[i] == true) break;
    	}
    }
    return isPossible[0];
}
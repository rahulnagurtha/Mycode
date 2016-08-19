int Solution::diffPossible(vector<int> &A, int B) {
    for (int i = 0, j = 1; i < A.size(); ++i) {
        for (j = max(j,i+1); j < A.size(); ++j) {
            if(A[j] - A[i] == B) return 1;
            if(A[j] - A[i] > B) break;
        }
    }
    return 0;
}
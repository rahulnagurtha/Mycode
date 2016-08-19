int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0) return 0;
    int cur = 1;
    for (int i = 1; i < A.size(); ++i) {
        if(cur >= 2 && A[cur-1] == A[cur-2] && A[cur-1] == A[i]) continue;
        else {
            A[cur++] = A[i];
        }
    }
    A.resize(cur);
    return cur;
}
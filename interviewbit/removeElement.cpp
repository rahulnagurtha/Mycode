int Solution::removeElement(vector<int> &A, int B) {
    int cur = 0;
    int len = 0;
    for (int i = 0; i < A.size(); ++i) {
        if(A[i] != B) {
            swap(A[cur],A[i]);
            len++;
            cur++;
        }
    }
    A.resize(len);
    return len;
}
void Solution::arrange(vector<int> &A) {
    int sz = A.size();
    int original;
    for(int i = 0 ; i < sz ;i++) {
        original = A[A[i]]%sz;
        A[i] += original*sz;
    }
    for(int i = 0 ; i < sz ;i++) {
        A[i] = A[i] / sz;
    }
    return;
}

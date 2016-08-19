vector<int> Solution::maxone(vector<int> &A, int B) {
    int L = -1,R = -2;
    int ans = 0;
    int numZeroes = 0;
    for (int i = 0, j = 0; i < A.size(); ++i) {
        j = max(i,j);
        while(j < A.size() && (numZeroes < B || A[j] == 1)) {
            if(A[j] == 0) numZeroes++;
            j++;
        }
        if(j - i > ans) {
            ans = j - i;
            L = i;
            R = j-1;
        }
        if(A[i] == 0 && i != j) numZeroes--;
    }
    vector<int> v;
    for (int i = L; i <= R; ++i) {
        v.push_back(i);
    }
    return v;
}
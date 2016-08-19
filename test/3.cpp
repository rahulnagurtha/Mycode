vector<int> Solution::maxone(vector<int> &A, int M) {
    vector<int> res;
    int n = A.size();
    int j = 0, nz = 0, idx = 0, best = 0;
    for(int i=0; i<n; i++) {
        while(j < n && (nz < M || A[j] == 1)) {
            if(A[j] == 0) nz++;
            j++;
        }
        idx = (j-i > best)?(i):(idx);
        best = max(best, j-i);
        if(j > i && A[i]==0) nz--;
        j = max(j, i+1);
    }
    
    for(int i=idx; i<idx+best; i++) res.push_back(i);
    return res;
}
void Solution::nextPermutation(vector<int> &A) {
    int searchIdx = A.size();
    for(int i = A.size()-2; i >= 0;i--) {
        if(A[i] < A[i+1]) {
            searchIdx = i+1;
            break;
        }
    }
    if(searchIdx == A.size()) {
        reverse(A.begin(),A.end());
    }
    else {
        for(int i = A.size() - 1; i >= searchIdx ; i--) {
            if(A[i] > A[searchIdx-1]) {
                swap(A[i],A[searchIdx-1]);
                break;
            }
        }
        int lft = searchIdx,ryt = A.size()-1;
        while(lft < ryt) {
            swap(A[lft],A[ryt]);
            lft++;
            ryt--;
        }
    }
    return;
}

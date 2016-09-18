int upperBound(vector<int> &A, int B,int l,int r) {
    int mid = (l+r)/2;
    if(A[mid] == B) return mid;
    if(l == r) return (A[l] > B ? l : A.size());
    if(A[mid] < B) return upperBound(A,B,mid+1,r);
    else return upperBound(A,B,l,mid);
}

int Solution::searchInsert(vector<int> &A, int B) {
    return upperBound(A,B,0,A.size() - 1);
}
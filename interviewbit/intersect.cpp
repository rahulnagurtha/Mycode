vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> common;
    for (int i = 0,j = 0; i < A.size() && j < B.size();) {
        if(A[i] == B[j]) {
            common.push_back(A[i]);
            i++;j++;
        }
        else if(A[i] > B[j]) j++; 
        else i++;
    }
    return common;
}
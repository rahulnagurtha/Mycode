int Solution::firstMissingPositive(vector<int> &A) {
    int original,ans = A.size() + 1;
    for(int i = 0;i < A.size(); i++) {
        if(A[i] <= 0) A[i] = A.size() + 5;
    }
    for(int i = 0;i < A.size(); i++) {
        original = abs(A[i]);
        if(original <= A.size()) A[original-1] = -1*A[original-1];
    }
    for(int i = 0;i < A.size(); i++) {
        if(A[i] > 0) {
            ans = i+1;
            break;
        }
    }
    return ans;
}

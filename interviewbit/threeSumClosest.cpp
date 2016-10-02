int Solution::threeSumClosest(vector<int> &A,int B) {
    sort(A.begin(),A.end());
    int diff = INT_MAX;
    int sum = INT_MAX;
    for (int k = 0; k < A.size(); ++k) {
        for (int i = 0,j = A.size()-1; i < A.size(); ++i) {
            if(i == k) {
                continue;
            }
            for (; j > i;) {
                if(j == k) {
                    j--;
                    continue;
                }
                if(A[i] + A[j] + A[k] >= B) {
                    if(diff > abs(B - (A[i] + A[j] + A[k])) ) {
                        sum = A[i] + A[j] + A[k];
                        diff = abs(B - (A[i] + A[j] + A[k]));
                    }
                    j--;
                }
                else {
                    if(diff > abs(B - (A[i] + A[j] + A[k])) ) {
                        sum = A[i] + A[j] + A[k];
                        diff = abs(B - (A[i] + A[j] + A[k]));
                    }
                    break;
                }
            }
        }

    }
    return sum;
}
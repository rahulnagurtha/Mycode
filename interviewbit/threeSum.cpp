vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int> > dupResult;
    vector<vector<int> > result;
    for (int k = 0; k < A.size(); ++k) {
        for (int i = 0,j = A.size()-1; i < A.size(); ++i) {
            if(i == k) continue;
            for (; j > i;) {
                if(j == k) {
                    j--;
                    continue;
                }
                if(A[i] + A[j] + A[k] == 0) {
                    vector<int> tmp;
                    tmp.push_back(A[i]);
                    tmp.push_back(A[j]);
                    tmp.push_back(A[k]);
                    sort(tmp.begin(),tmp.end());
                    dupResult.push_back(tmp);
                    j--;
                }
                else if(A[i] + A[j] + A[k] > 0) j--;
                else break;
            }
        }

    }
    if(dupResult.size() == 0) return result;
    sort(dupResult.begin(),dupResult.end());
    result.push_back(dupResult[0]);
    for (int i = 1; i < dupResult.size(); ++i) {
        if(result.back() != dupResult[i]) {
            result.push_back(dupResult[i]);
        }
    }
    return result;
}
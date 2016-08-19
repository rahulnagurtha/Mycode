string Solution::longestCommonPrefix(vector<string> &A) {
    string ans;
    int len = INT_MAX;
    for (int i = 0; i < A.size(); ++i) {
        len = min((int)A[i].size(),len);
    }
    for (int i = 0; i < len; ++i) {
        bool Same = true;
        for (int j = 1; j < A.size(); ++j) {
            if(A[j][i] != A[j-1][i]) Same = false;
        }
        if(!Same) break;
        ans += A[0][i];
    }
    return ans;
}
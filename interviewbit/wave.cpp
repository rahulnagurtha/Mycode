vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(),A.end());
    int cur = 0;
    vector<int> ans;
    while(ans.size() < A.size()) {
        if(cur + 1 < A.size()) ans.push_back(A[cur+1]);
        ans.push_back(A[cur]);
        cur += 2;
    }
    return ans;
}

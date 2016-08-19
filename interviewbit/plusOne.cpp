vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> ans;
    int carry = 1;
    int idx = 0;
    for(int i = 0;i < A.size();i++) {
        if(A[i] == 0) idx++;
        else break;
    }
    for(int i = A.size()-1 ; i>= idx; i--) {
        ans.push_back((A[i]+carry)%10);
        carry = (A[i] + carry)/10;
    }
    if(carry > 0) ans.push_back(carry);
    reverse(ans.begin(),ans.end());
    return ans;
}

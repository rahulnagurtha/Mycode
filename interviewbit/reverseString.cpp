string Solution::reverseString(string A) {
    stack<char> T;
    string ans;
    for(int i = 0 ; i < A.size() ; i++) {
        T.push(A[i]);
    }
    while(!T.empty()) {
        ans += T.top();
        T.pop();
    }
    return ans;
}

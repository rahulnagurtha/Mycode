vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > ans;
    if(A > 0) {
        vector<int> tmp;
        tmp.push_back(1);
        ans.push_back(tmp);
    }
    for(int i = 2; i <= A; i++) {
        vector<int> cur;
        vector<int> last;
        if(ans.size() > 0) last = ans.back();
        for(int j = 0; j < i; j++) {
            int tmp = 0;
            if(j-1 >= 0 && j-1 <= i-2) {
                tmp += last[j-1];
            }
            if(j >= 0 && j <= i-2) {
                tmp += last[j];
            }
            cur.push_back(tmp);
        }
        ans.push_back(cur);
    }
    return ans;
}
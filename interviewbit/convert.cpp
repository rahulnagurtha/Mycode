string Solution::convert(string A, int B) {
    if(B == 1) return A;
    string going = "down";
    vector<string> bucket;
    string ans;
    int idx = 0;
    for (int i = 0; i < B; ++i) {
        bucket.push_back(ans);
    }
    for (int i = 0; i < A.size(); ++i) {
        if(going == "down") {
            bucket[idx] += A[i];
            if(idx+1 == B) {
                going = "up";
                idx--;
            }
            else idx++;
        }
        else {
            bucket[idx] += A[i];
            if(idx == 0) {
                going = "down";
                idx++;
            }
            else idx--;
        }
    }
    for (int i = 0; i < B; ++i) {
        ans += bucket[i];
    }
    return ans;
}
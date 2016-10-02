string Solution::longestPalindrome(string A) {
    int tmp;
    int L,R;
    int len = 0;
    int lft,ryt;
    string ans;
    for (int i = 0; i < A.size(); ++i) {
        //this can be the middle element
        tmp = 1;
        lft = i - 1;
        ryt = i + 1;
        while(lft >= 0 && ryt < A.size() && A[lft] == A[ryt]) {
            tmp += 2;
            lft--;
            ryt++;
        }
        if(tmp > len) {
            len = tmp;
            L = lft + 1;
            R = ryt - 1;
        }
        else if(tmp == len){
            if(L > lft + 1) {
                L = lft + 1;
                R = ryt - 1;
            }
        }
        //this can be the left middle
        tmp = 0;
        lft = i;
        ryt = i+1;
        while(lft >= 0 && ryt < A.size() && A[lft] == A[ryt]) {
            tmp += 2;
            lft--;
            ryt++;
        }
        if(tmp > len) {
            len = tmp;
            L = lft + 1;
            R = ryt - 1;
        }
        else if(tmp == len){
            if(L > lft + 1) {
                L = lft + 1;
                R = ryt - 1;
            }
        }
    }
    for (int i = L; i <= R; ++i) {
        ans += A[i];
    }
    return ans;
}
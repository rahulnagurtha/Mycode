void Solution::reverseWords(string &A) {
    string B;
    int lft,ryt;
    bool isFirst = true;
    for (int i = 0; i < A.size(); ++i) {
        if(A[i] == ' ') continue;
        if(!isFirst) {
            B += ' ';
        }
        isFirst = false;
        lft = i;
        while(i < A.size() && A[i] != ' ') {
            ryt = i;
            i++;
        }
        for (int j = ryt; j >= lft; --j) {
            B += A[j];
        }
    }
    reverse(B.begin(),B.end());
    A = B;
    return;
}
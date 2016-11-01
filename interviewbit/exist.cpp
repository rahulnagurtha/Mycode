int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

bool isInside(int x,int y,int m,int n) {
    return (0 <= x && x < m && 0 <= y && y < n);
}


int Solution::exist(vector<string> &A, string B) {
    int dp[A.size()][A[0].size()][B.size()];
    for (int idx = B.size() - 1; idx >= 0; --idx) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                dp[i][j][idx] = (A[i][j] == B[idx]);
                if(idx + 1 >= B.size()) continue;
                bool adj = false;
                for (int k = 0; k < 4; ++k) {
                    int xx = i + dX[k];
                    int yy = j + dY[k];
                    if(isInside(xx,yy,A.size(),A[0].size())) {
                        adj |= dp[xx][yy][idx+1];
                    }
                }
                dp[i][j][idx] &= adj;
            }
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            if(dp[i][j][0]) return 1;
        }
    }
    return 0;
}
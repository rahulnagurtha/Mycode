void Solution::setZeroes(vector<vector<int> > &A) {
    int numRows = A.size();
    int numColumns = A[0].size();
    bool row[A.size()+5],column[A[0].size()+5];
    for(int i = 0;i < A.size(); i++) {
        row[i] = false;
    }
    for(int j = 0;j < A[0].size(); j++) {
        column[j] = false;
    }
    for(int i = 0; i < numRows;i++) {
        for(int j = 0; j < numColumns;j++) {
            if(A[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for(int i = 0; i < numRows;i++) {
        for(int j = 0; j < numColumns;j++) {
            if(row[i] || column[j]) {
                A[i][j] = 0;
            }
        }
    }
    return;
}

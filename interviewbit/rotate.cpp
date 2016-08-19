void Solution::rotate(vector<vector<int> > &A) {
    int x1,x2,y1,y2;
    x1 = 0;x2 = A.size()-1;
    y1 = 0;y2 = A.size()-1;
    while(x1 < x2) {
        for(int xx1 = x1; xx1 <= x2 ;xx1++) {
            swap(A[xx1][y1],A[xx1][y2]);
        }
        for(int yy1 = y1 + 1,yy2 = y2 - 1; yy1 < yy2;yy1++,yy2--) {
            swap(A[x1][yy1],A[x1][yy2]);
            swap(A[x2][yy1],A[x2][yy2]);
        }
        for(int xx1 = x1,yy1 = y2; xx1 < x2;yy1--,xx1++) {
            swap(A[xx1][y1],A[x2][yy1]);
        }
        for(int xx1 = x1 + 1,yy1 = y2 - 1; xx1 < x2;yy1--,xx1++) {
            swap(A[xx1][y2],A[x1][yy1]);
        }
        x1++;
        x2--;
        y1++;
        y2--;
    }
    return;
}
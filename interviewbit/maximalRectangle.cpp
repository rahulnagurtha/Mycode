int Solution::maximalRectangle(vector<vector<int> > &A) {
	int ans = 0;
    int length[A.size()+5][A[0].size()+5];
    int breadth[A.size()+5][A[0].size()+5];
    int dimL[A.size()+5][A[0].size()+5];
    int dimB[A.size()+5][A[0].size()+5];
    for (int i = 0; i < A.size(); ++i) {
    	length[i][A[0].size()-1] = (A[i][A[0].size()-1] == 0 ? 0 : 1);
    }
    for (int j = 0; j < A[0].size(); ++j) {
    	breadth[A.size()-1][j] = (A[A.size()-1][j] == 0 ? 0 : 1);
    }
   	//fill length
    for (int j = A[0].size() - 2; j >= 0; --j) {
    	for (int i = 0; i < A.size(); ++i) {
    		length[i][j] = (A[i][j] == 0 ? 0 : 1 + length[i][j+1]);
    	}
    }
    //fill breadth
    for (int i = A.size() - 2; i >= 0; --i) {
    	for (int j = 0; j < A[0].size(); ++j) {
    		breadth[i][j] = (A[i][j] == 0 ? 0 : 1 + breadth[i+1][j]);
    	}
    }
    //find answer
    for (int i = A.size() - 1; i >= 0; --i) {
    	for (int j = A[i].size() - 1; j >= 0; --j) {
    		int b = INT_MAX;
    		for (int k = j; k < j + length[i][j]; ++k) {
    			if(A[i][k] == 0) break;
    			b = min(b,breadth[i][k]);
    			ans = max(ans,b*(k-j+1));
    		}
    	}
    }
    return ans;
}
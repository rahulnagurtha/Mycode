int Solution::maxProduct(const vector<int> &A) {
    bool canPositive,canNegative;
    int maxP,maxN;
    int ans = A.back();
    if(A.back() >= 0) {
    	canPositive = true;
    	canNegative = false;
    	maxP = A.back();
    	maxN = -1;
    }
    else {
    	canPositive = false;
    	canNegative = true;
    	maxP = -1;
    	maxN = A.back();
    }
    for (int i = A.size() - 1; i >= 0; --i) {
    	if(A[i] >= 0) {
    		if(canPositive) {
    			maxP = max(A[i],A[i]*maxP);
    		}
    		else {
    			maxP = A[i];
    		}
    		if(canNegative) {
    			maxN = A[i]*maxN;
    		}
    		canPositive = true;
    		if(canPositive) ans = max(ans,maxP);
    		if(canNegative) ans = max(ans,maxN);
    	}
    	else {
    		int mp,mn;
    		bool cp,cn;
    		if(canNegative) {
    			mp = A[i]*maxN;
    		}
    		else {
    			cp = false;
    		}
    		if(canPositive) {
    			mn = max(A[i],A[i]*maxP);
    			cn = true;
    		}
    		else {
    			mn = A[i];
    			cn = true;
    		}
    		canPositive = cp;
    		canNegative = cn;
    		maxP = mp;
    		maxN = mn;
    		if(canPositive) ans = max(ans,maxP);
    		if(canNegative) ans = max(ans,maxN);
    	}
    }
    return ans;
}
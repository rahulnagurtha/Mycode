int lowerBound(const vector<int> &A,int B,int l,int r) {
	if(l > r) return -1;
	int mid = (l+r)/2;
	if(l == r) return (A[l] == B ? l : -1);
	if(A[mid] >= B) return lowerBound(A,B,l,mid);
	else return lowerBound(A,B,mid+1,r);
}

int upperBound(const vector<int> &A,int B,int l,int r) {
	if(l > r) return -1;
	if(l == r) return (A[l] == B ? l : -1);
	int mid = (l+r+1)/2;
	if(A[mid] < B) return upperBound(A,B,mid+1,r);
	else if(A[mid] == B) return upperBound(A,B,mid,r);
	else return upperBound(A,B,l,mid-1);
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
	vector<int> ans;
	int L = lowerBound(A,B,0,A.size()-1);
	int R = upperBound(A,B,0,A.size()-1);
	ans.push_back(L);
	ans.push_back(R);
	return ans;
}
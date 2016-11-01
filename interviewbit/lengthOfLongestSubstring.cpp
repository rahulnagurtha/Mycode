int Solution::lengthOfLongestSubstring(string A) {
    unordered_set<char> data;
    int ans = 0;
    for (int i = 0,j = 0; i < A.size(); ++i) {
    	for (j = max(j,i); j < A.size(); ++j) {
    		if(data.find(A[j]) == data.end()) data.insert(A[j]);
    		else break;
    	}
    	ans = max(ans,data.size());
    	data.erase(A[i]);
    }
    return ans;
}
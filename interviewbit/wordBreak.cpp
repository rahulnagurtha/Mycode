int Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string> dictionary;
    for (int i = 0; i < B.size(); ++i) {
    	dictionary.insert(B[i]);
    }
    bool isPossible[A.size() + 5];
    isPossible[A.size()] = true;
    for (int i = A.size() - 1; i >= 0; --i) {
    	string soFar = "";
    	isPossible[i] = false;
    	for (int j = i; j < A.size(); ++j) {
    		soFar += A[j];
    		if(dictionary.find(soFar) != dictionary.end()) {
    			isPossible[i] = isPossible[j + 1];
    		}
    		if(isPossible[i] == true) break;
    	}
    }
    return isPossible[0];
}
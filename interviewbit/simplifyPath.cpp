string Solution::simplifyPath(string A) {
	stack<string> T;
	string tmp;
	string ans;
	for (int i = 1; i < A.size();i++) {
		if(A[i] != '/') tmp += A[i];
		else {
			if(tmp == ".") tmp = "";
			else if(tmp == "..") {
			    if(!T.empty()) T.pop();   
			}
			else T.push(tmp);
			tmp = "";
		}
	}
	if(tmp.size() != 0) {
		if(tmp == ".") tmp = "";
		else if(tmp == "..") {
		    if(!T.empty()) T.pop();   
		}
		else T.push(tmp);
	}
	while(!T.empty()) {
		if(T.top().size() != 0) ans = '/' + T.top() + ans;
		T.pop();
	}
	if(ans.size() == 0) ans = "/";
	return ans;
}
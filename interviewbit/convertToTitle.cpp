string Solution::convertToTitle(int A) {
    string ans;
    while(A > 0) {
    	if(A%26 != 0) {
    		ans += char('A'+ A%26 - 1);
    		A = A/26;
    	}
    	else {
    		ans += 'Z';
    		A = A/26;
    		A--;
    	}
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
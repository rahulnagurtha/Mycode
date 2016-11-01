vector<string> ans;
map<char,string> data;


void recurse(int pos,string &src,string &soFar) {
	if (pos == src.size()) {
		data.pb(soFar);
		return;
	}
	string possible = src[pos];
	for (int i = 0; i < possible.size(); ++i) {
		soFar.pb(possible[i]);
		recurse(pos+1,src,soFar);
		soFar.pop_back();
	}
	return;
}

vector<string> Solution::letterCombinations(string A) {
    ans.clear();
    data.clear();
    data['0'] = "0";
    data['1'] = "1";
    data['2'] = "abc";
    data['3'] = "def";
    data['4'] = "ghi";
    data['5'] = "jkl";
    data['6'] = "mno";
    data['7'] = "pqrs";
    data['8'] = "tuv";
    data['9'] = "wxyz";
    string tmp;
    recurse(0,A,tmp);
    return ans;
}
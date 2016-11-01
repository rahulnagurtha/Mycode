vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int> > data;
    vector<vector<int> > ans;
    for (int i = 0; i < A.size(); ++i) {
    	vector<int> tmp;
    	for (int j = 0; j < 26; ++j) {
    		tmp.push_back(0);
    	}
    	for (int j = 0; j < A[i].size(); ++j) {
    		tmp[A[i][j] - 'a']++;
    	}
    	string toPush;
    	for (int j = 0; j < 26; ++j) {
    		toPush += to_string(tmp[j]);
    	}
    	data[toPush].push_back(i + 1);
    }
    for(int i = 0; i < data.bucket_count(); ++i) {
    	for ( auto local_it = data.begin(i); local_it != mymap.end(i); ++local_it) {
      		ans.push_back(local_it->second);
    	}
	}
}
int Solution::isValidSudoku(const vector<string> &A) {
    map<pair<int,int>,unordered_set<char> > box;
    unordered_set<char> row[9];
    unordered_set<char> column[9];
    for (int i = 0; i < A.size(); ++i) {
    	for (int j = 0; j < A[i].size(); ++j) {
    		if(A[i][j] == '.') continue;
    		//insert into correspoding row
    		if(row[i].find(A[i][j]) != row[i].end()) return 0;
    		row[i].insert(A[i][j]);
    		//insert into correspoding column
    		if(column[j].find(A[i][j]) != column[j].end()) return 0;
    		column[j].insert(A[i][j]);
    		//insert into correspoding box
    		if(box[make_pair(i/3,j/3)].find(A[i][j]) != box[make_pair(i/3,j/3)].end()) return 0;
    		box[make_pair(i/3,j/3)].insert(A[i][j]);
    	}
    }
    return 1;
}
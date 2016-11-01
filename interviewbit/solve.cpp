int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};


bool isInside(int x,int y,int m,int n) {
	return (0 <= x && x < m && 0 <= y && y < n);
}

void dfs(int x,int y,vector<vector<bool> > &visited,vector<vector<char> > &A) {
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int xx = x + dX[i];
		int yy = y + dY[i];
		if(isInside(xx,yy,visited.size(),visited[0].size()) && A[xx][yy] == 'O' && !visited[xx][yy]) {
			dfs(xx,yy,visited,A);
		}
	}
	return;
}

void Solution::solve(vector<vector<char> > &A) {
    vector<vector<bool> > visited;
    visited.resize(A.size());
    for (int i = 0; i < A.size(); ++i) {
    	visited[i].resize(A[i].size());
    }
    for (int i = 0; i < visited.size(); ++i) {
    	for (int j = 0; j < visited[i].size(); ++j) {
    		visited[i][j] = false;
    	}
    }
    //left column
    for (int i = 0, j = 0; i < A.size(); ++i) {
    	if(!visited[i][j] && A[i][j] == 'O') {
    		dfs(i,j,visited,A);
    	}
    }
    //right column
    for (int i = 0, j = A[0].size() - 1; i < A.size(); ++i) {
    	if(!visited[i][j] && A[i][j] == 'O') {
    		dfs(i,j,visited,A);
    	}
    }
    //top row
    for (int j = 0, i = 0; j < A[0].size(); ++j) {
    	if(!visited[i][j] && A[i][j] == 'O') {
    		dfs(i,j,visited,A);
    	}
    }
    //bottom row
    for (int j = 0, i = A.size() - 1; j < A[0].size(); ++j) {
    	if(!visited[i][j] && A[i][j] == 'O') {
    		dfs(i,j,visited,A);
    	}
    }
    for (int i = 0; i < visited.size(); ++i) {
    	for (int j = 0; j < visited[i].size(); ++j) {
    		if(!visited[i][j] && A[i][j] == 'O') A[i][j] = 'X';
    	}
    }
    return;
}
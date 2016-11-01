bool isInRow[9][9];
bool isInColumn[9][9];
bool isInGrid[3][3][9];

bool isValid(vector<vector<char> > &A) {
	set<char> row[9];
	set<char> column[9];
	set<char> grid[3][3];
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			//add to grid
			if(grid[i/3][j/3].find(A[i][j]) != grid[i/3][j/3].end())
				return false;
			grid[i/3][j/3].insert(A[i][j]);
			//add to row
			if(row[i].find(A[i][j]) != row[i].end())
				return false;
			row[i].insert(A[i][j]);
			//add to column
			if(column[j].find(A[i][j]) != column[j].end())
				return false;
			column[j].insert(A[i][j]);
		}
	}
	return true;
}

bool recurse(int x,int y,vector<vector<char> > &A) {
	if(x == 8 && y == 8) {
		for (int i = 0; i < 9; ++i) {
			if(!isInGrid[2][2][i]) {
				A[8][8] = '1' + i;
				break;
			}
		}
		return isValid(A);
	}
	if(A[x][y] != '.') return (y == 8 ? recurse(x + 1, 0, A) : recurse(x, y + 1, A));
	bool retVal = false;
	for (int i = 0; i < 9; ++i) {
		if(!isInGrid[x/3][y/3][i] && !isInRow[x][i] && !isInColumn[y][i]) {
			assert(isInGrid[x/3][y/3][i] == false);
			//set
			isInGrid[x/3][y/3][i] = true;
			isInRow[x][i] = true;
			isInColumn[y][i] = true;
			A[x][y] = i + '1';
			retVal = (y == 8 ? recurse(x + 1, 0, A) : recurse(x, y + 1, A));
			if(retVal) return true;
			//unset
			A[x][y] = '.';
			isInGrid[x/3][y/3][i] = false;
			isInRow[x][i] = false;
			isInColumn[y][i] = false;
		}
	}
	return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    memset(isInRow,false,sizeof(isInRow));
    memset(isInGrid,false,sizeof(isInGrid));
    memset(isInColumn,false,sizeof(isInColumn));
    for (int i = 0; i < 9; ++i) {
    	for (int j = 0; j < 9; ++j) {
    		if(A[i][j] != '.') {
    			isInGrid[i/3][j/3][A[i][j]-'1'] = true;
    			isInRow[i][A[i][j]-'1'] = true;
    			isInColumn[j][A[i][j]-'1'] = true;
    		}
    	}
    }
    recurse(0,0,A);
    return;
}
#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

class JumpingBoard
{
private:
	VS grid;
	int ans;
	int dp[55][55];
	int rows,columns;
	bool inStack[55][55];
	bool visited[55][55];
public:
	void init(int r,int c,VS board);
	bool isOut(int x,int y);
	bool isThereCycle(int xx,int yy);
	int maxFrom(int xx,int yy);
	int maxJumps(VS board);
};

void JumpingBoard::init(int r,int c,VS board) {
	ans = 0;
	rows = r;
	columns = c;
	fill(dp,-1);
	grid = board;
	fill(inStack,false);
	fill(visited,false);
	return;
}

bool JumpingBoard::isOut(int x,int y) {
	if(x >= 0 && x < rows && y >= 0 && y < columns) return false;
	return true;
}

bool JumpingBoard::isThereCycle(int xx,int yy) {
	if(grid[xx][yy] == 'H') return false;
	visited[xx][yy] = true;
	inStack[xx][yy] = true;
	bool l,r,u,d;
	int numMoves = grid[xx][yy] - '0';
	u = isOut(xx - numMoves,yy);
	d = isOut(xx + numMoves,yy);
	l = isOut(xx,yy - numMoves);
	r = isOut(xx,yy + numMoves);
	if(!u) {
		if(inStack[xx - numMoves][yy]) {
			inStack[xx][yy] = false;
			return true;
		}
		if(!visited[xx - numMoves][yy]) u = isThereCycle(xx - numMoves,yy);
	}
	else u = false;
	if(!d) {
		if(inStack[xx + numMoves][yy]) {
			inStack[xx][yy] = false;
			return true;
		}
		if(!visited[xx + numMoves][yy]) d = isThereCycle(xx + numMoves,yy);
	}
	else d = false;
	if(!l) {
		if(inStack[xx][yy - numMoves]) {
			inStack[xx][yy] = false;
			return true;
		}
		if(!visited[xx][yy - numMoves]) l = isThereCycle(xx,yy - numMoves);
	}
	else l = false;
	if(!r) {
		if(inStack[xx][yy + numMoves]) {
			inStack[xx][yy] = false;
			return true;
		}
		if(!visited[xx][yy + numMoves]) r = isThereCycle(xx,yy + numMoves);
	}
	else r = false;
	inStack[xx][yy] = false;
	return (l || r || u || d);
}

int JumpingBoard::maxFrom(int xx,int yy) {
	if(dp[xx][yy] != -1) return dp[xx][yy];
	int l,r,u,d,numMoves;
	l = r = u = d = 1;
	numMoves = grid[xx][yy] - '0';
	if(!isOut(xx - numMoves,yy) && grid[xx - numMoves][yy] != 'H') {
		u = maxFrom(xx - numMoves,yy) + 1;
	}
	if(!isOut(xx + numMoves,yy) && grid[xx + numMoves][yy] != 'H') {
		d = maxFrom(xx + numMoves,yy) + 1;
	}
	if(!isOut(xx,yy - numMoves) && grid[xx][yy - numMoves] != 'H') {
		l = maxFrom(xx,yy - numMoves) + 1;
	}
	if(!isOut(xx,yy + numMoves) && grid[xx][yy + numMoves] != 'H') {
		r = maxFrom(xx,yy + numMoves) + 1;
	}
	return (dp[xx][yy] = max(l,max(r,max(u,d))));
}

int JumpingBoard::maxJumps(VS board) {
	init(board.size(),board[0].size(),board);
	if(isThereCycle(0,0)) return -1;
	return maxFrom(0,0);
}

int main()
{
    freopen("in.txt", "r", stdin);
	int t;
	VS board;
	string tmp;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> tmp;
		board.pb(tmp);
	}
	JumpingBoard test;
	cout << test.maxJumps(board) << endl;
}
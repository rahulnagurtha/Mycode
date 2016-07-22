#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define FILL(a,v)               memset(a,v,sizeof a)
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

class CollectingRiders
{
public:
	bool visited[11][11];
	vector<VOVI> minSteps;
	int rows,columns;
	VOII riders;
	int ans;
	int isOut(int x,int y) {
		if(x >= 0 && x < rows && y >= 0 && y < columns) {
			return false;
		}
		return true;
	}

	void init() {
		ans = 1000000000;
		minSteps.resize(riders.size());
		for (int i = 0; i < minSteps.size(); ++i) {
			minSteps[i].resize(rows);
		}
		for (int i = 0; i < minSteps.size(); ++i) {
			for (int j = 0; j < minSteps[i].size(); ++j) {
				minSteps[i][j].resize(columns);
			}
		}
		return;
	}

	int minimalMoves(VS board);
};

int CollectingRiders::minimalMoves(VS board) {
	rows = board.size();
	columns = board[0].size();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if(board[i][j] != '.') riders.pb(mp(i,j));
		}
	}
	init();
	for (int i = 0; i < riders.size(); ++i) {
		for (int j = 0; j < rows; ++j) {
			fill(minSteps[i][j].begin(),minSteps[i][j].end(),100000);	
		}
		deque<PII> Q;
		PII cur;
		int xx,yy;
		Q.push_back(riders[i]);
		FILL(visited,false);
		minSteps[i][riders[i].FF][riders[i].SS] = 0;
		visited[riders[i].FF][riders[i].SS] = true;
		while(!Q.empty()) {
			xx = Q.front().FF;
			yy = Q.front().SS;
			Q.pop_front();
			
			if(!isOut(xx+1,yy+2) && !visited[xx+1][yy+2]) {
				minSteps[i][xx+1][yy+2] = 1+minSteps[i][xx][yy];
				visited[xx+1][yy+2] = true;
				Q.pb(mp(xx+1,yy+2));
			}
			if(!isOut(xx+1,yy-2) && !visited[xx+1][yy-2]) {
				minSteps[i][xx+1][yy-2] = 1+minSteps[i][xx][yy];
				visited[xx+1][yy-2] = true;
				Q.pb(mp(xx+1,yy-2));
			}
			if(!isOut(xx+2,yy+1) && !visited[xx+2][yy+1]) {
				minSteps[i][xx+2][yy+1] = 1+minSteps[i][xx][yy];
				visited[xx+2][yy+1] = true;
				Q.pb(mp(xx+2,yy+1));
			}
			if(!isOut(xx+2,yy-1) && !visited[xx+2][yy-1]) {
				minSteps[i][xx+2][yy-1] = 1+minSteps[i][xx][yy];
				visited[xx+2][yy-1] = true;
				Q.pb(mp(xx+2,yy-1));
			}
			if(!isOut(xx-1,yy+2) && !visited[xx-1][yy+2]) {
				minSteps[i][xx-1][yy+2] = 1+minSteps[i][xx][yy];
				visited[xx-1][yy+2] = true;
				Q.pb(mp(xx-1,yy+2));
			}
			if(!isOut(xx-1,yy-2) && !visited[xx-1][yy-2]) {
				minSteps[i][xx-1][yy-2] = 1+minSteps[i][xx][yy];
				visited[xx-1][yy-2] = true;
				Q.pb(mp(xx-1,yy-2));
			}
			if(!isOut(xx-2,yy+1) && !visited[xx-2][yy+1]) {
				minSteps[i][xx-2][yy+1] = 1+minSteps[i][xx][yy];
				visited[xx-2][yy+1] = true;
				Q.pb(mp(xx-2,yy+1));
			}
			if(!isOut(xx-2,yy-1) && !visited[xx-2][yy-1]) {
				minSteps[i][xx-2][yy-1] = 1+minSteps[i][xx][yy];
				visited[xx-2][yy-1] = true;
				Q.pb(mp(xx-2,yy-1));
			} 
		}
		for (int j = 0; j < rows; ++j) {
			for (int k = 0; k < columns; ++k) {
				minSteps[i][j][k] = ceil(minSteps[i][j][k],board[riders[i].FF][riders[i].SS] - '0');
			}
		}
	}
	PII target;
	int curAns;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			target.FF = i;
			target.SS = j;
			curAns = 0;
			for (int k = 0; k < riders.size(); ++k) {
				curAns += minSteps[k][target.FF][target.SS];
			}
			if(curAns < ans) ans = curAns;
		}
	}
	if(ans >= 100000) ans = -1;
	return ans;
}


int main()
{
	VS board;
	string tmp;
	int rows;
	cin >> rows;
	for (int i = 0; i < rows; ++i) {
		cin >> tmp;
		board.pb(tmp);
	}
	CollectingRiders test;
	cout << test.minimalMoves(board) << endl;
}
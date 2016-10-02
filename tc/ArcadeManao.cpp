#include <bits/stdc++.h>

using namespace std;

#define SYNC                    ios_base::sync_with_stdio(0)
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

class ArcadeManao
{
public:
	int ladderSz,m,n;
	bool visited[55][55];
	vector<string> grid;

	void dfs(int x,int y) {
		visited[x][y] = true;
		for (int i = 1; (x + i < n) && (i <= ladderSz); ++i) {
			if((!visited[x + i][y]) && (grid[x + i][y] == 'X')) dfs(x + i,y);
		}
		for (int i = 1; (x - i >= 0) && (i <= ladderSz); ++i) {
			if((!visited[x - i][y]) && (grid[x - i][y] == 'X')) dfs(x - i,y);
		}
		if(y - 1 >= 0 && !visited[x][y-1] && grid[x][y-1] == 'X') {
			dfs(x,y-1);
		}
		if(y + 1 < m && !visited[x][y+1] && grid[x][y+1] == 'X') {
			dfs(x,y+1);
		}
		return;
	}

	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		grid = level;
		n = level.size();
		m = level[0].size();
		for (ladderSz = 0; ladderSz < 51; ++ladderSz) {
			fill(visited,false);
			dfs(level.size()-1,0);
			if(visited[coinRow-1][coinColumn-1]) return ladderSz;
		}
		return -1;
	}
};


int main()
{
	ArcadeManao test;
    vector<string> grid;
    string tmp;
    int x,y,n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	grid.pb(tmp);
    }
    cin >> x >> y;
    cout << test.shortestLadder(grid,x,y) << endl;
    return 0;
}
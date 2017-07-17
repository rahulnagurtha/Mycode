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
#define N                     	100007

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};



class MovingCandies
{
public:
	ll dp[25][25][405];
	
	MovingCandies() {
		fill(dp,-1);
		return;
	}
	
	bool isValid(VS &t) {
		int cnt = 0;
		for (int i = 0; i < t.size(); ++i) {
			for (int j = 0; j < t[i].size(); ++j) {
				if(t[i][j] == '#') cnt++;
			}
		}
		return (cnt >= (t.size() + t[0].size() - 1));
	}

	bool isInside(int x,int y,VS &t) {
		return ( (0 <= x) && (x < t.size()) && (0 <= y) && (y < t[0].size()));
	}

	ll recurse(VS &t,int i,int j,int k) {
		if(dp[i][j][k] != -1) return dp[i][j][k];

		if(k == 0) {
			if((i == (t.size() - 1)) && (j == (t[0].size() - 1))) {
				dp[i][j][k] = (t[i][j] == '#' ? 0LL : 1LL);
			}
			else dp[i][j][k] = INT_MAX;
			return dp[i][j][k];
		}
		
		if((i == (t.size() - 1)) && (j == (t[0].size() - 1))) {
			return (t[i][j] == '#' ? 0LL : 1LL);
		}
		
		dp[i][j][k] = INT_MAX;
		for (int l = 0; l < 4; ++l) {
			int xx = i + dX[l];
			int yy = j + dY[l];
			if(!isInside(xx,yy,t)) continue;
			if(t[i][j] == '.') dp[i][j][k] = min(dp[i][j][k],1LL + recurse(t,xx,yy,k - 1));
			else dp[i][j][k] = min(dp[i][j][k],recurse(t,xx,yy,k - 1));
		}
		cout << i << "," << j << "," << k << " : " << dp[i][j][k] << endl;
		return dp[i][j][k];
	}
	int minMoved(VS t) {
		if(!isValid(t)) return -1;
		return (int)(recurse(t,0,0,402));
	}
};

int main()
{
	MovingCandies test;
	VS A;
	A.pb(".#...#.###.#");
	A.pb("#.#.##......");
	A.pb(".#.#......#.");
	A.pb("..#.......#.");
	A.pb("##..........");
	cout << test.minMoved(A) << endl;
	return 0;
}
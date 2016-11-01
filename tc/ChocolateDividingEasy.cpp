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


class ChocolateDividingEasy
{
public:
	int dp[55][55];
	int ans;
	int n,m;
	void init(VS &grid) {
		ans = 0;
		fill(dp,0);
		for (int i = 0; i < grid.size(); ++i) {
			int sum = 0;
			for (int j = 0; j < grid[i].size(); ++j) {
				sum += (grid[i][j] - '0');
				dp[i + 1][j + 1] = dp[i][j+1] + sum;
			}
		}
		return;
	}
	int getsum(int x1,int y1,int x2,int y2) {
		return (dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
	}
	void update(int x1,int x2,int y1,int y2) {
		int curAns = INT_MAX;
		//first row
		curAns = min(curAns,getsum(1,1,y1,x1));
		curAns = min(curAns,getsum(1,x1+1,y1,x2));
		curAns = min(curAns,getsum(1,x2+1,y1,m));
		//second row
		curAns = min(curAns,getsum(y1+1,1,y2,x1));
		curAns = min(curAns,getsum(y1+1,x1+1,y2,x2));
		curAns = min(curAns,getsum(y1+1,x2+1,y2,m));
		//third row
		curAns = min(curAns,getsum(y2+1,1,n,x1));
		curAns = min(curAns,getsum(y2+1,x1+1,n,x2));
		curAns = min(curAns,getsum(y2+1,x2+1,n,m));
		ans = max(ans,curAns);
		return;
	}
	int findBest(VS chocolate) {
		init(chocolate);
		n = chocolate.size();
		m = chocolate[0].size();
		for (int x1 = 1; x1 < m; ++x1) {
			for (int x2 = x1 + 1; x2 < m; ++x2) {
				for (int y1 = 1; y1 < n; ++y1) {
					for (int y2 = y1 + 1; y2 < n; ++y2) {
						update(x1,x2,y1,y2);
					}
				}
			}
		}
		return ans;
	}
};
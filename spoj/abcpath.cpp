#include <bits/stdc++.h>

using namespace std;

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

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

int h,w,t;

void solve() {
	vector<string> grid;
	vector<vector<PII> > Q; // Q[i] stores all the cells (i,j) with character ('A'+i)
	int dp[55][55] = {0}; //dp[i][j] is the maximum number of consecutive characters you can find starting with grid[i][j]
	int X,Y;
	VOII tp;
	for (int i = 0; i < 26; ++i) {
		Q.pb(tp);
	}
	string tmp;
	int ans = 0;
	for (int i = 0; i < h; ++i) {
		cin >> tmp;
		for (int j = 0; j < w; ++j) {
			Q[tmp[j]-'A'].pb(mp(i,j));
		}
		grid.pb(tmp);
	}
	for (int i = 0; i < Q[25].size(); ++i) {
		dp[Q[25][i].FF][Q[25][i].SS] = 1;
	}
	for (int i = 24; i >= 1; --i) {
		for (int j = 0; j < Q[i].size(); ++j) {
			X = Q[i][j].FF;
			Y = Q[i][j].SS;
			dp[X][Y] = 1;
			if((X >= 1) && (Y >= 1) && grid[X-1][Y-1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y-1]);
			}
			if((X >= 1) && grid[X-1][Y] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y]);
			}
			if((X >= 1) && (Y+1 < w) && grid[X-1][Y+1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y+1]);
			}
			if((Y >= 1) && grid[X][Y-1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X][Y-1]);
			}
			if((Y+1 < w) && grid[X][Y+1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X][Y+1]);
			}
			if((X+1 < h) && (Y >= 1) && grid[X+1][Y-1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y-1]);
			}
			if((X+1 < h) && grid[X+1][Y] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y]);
			}
			if((X+1 < h) && (Y+1 < w) && grid[X+1][Y+1] == char(65+i+1)) {
				dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y+1]);
			}
		}
	}
	for (int i = 0; i < Q[0].size(); ++i) {
		X = Q[0][i].FF;
		Y = Q[0][i].SS;
		dp[X][Y] = 1;
		if((X >= 1) && (Y >= 1) && grid[X-1][Y-1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y-1]);
		}
		if((X >= 1) && grid[X-1][Y] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y]);
		}
		if((X >= 1) && (Y+1 < w) && grid[X-1][Y+1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X-1][Y+1]);
		}
		if((Y >= 1) && grid[X][Y-1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X][Y-1]);
		}
		if((Y+1 < w) && grid[X][Y+1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X][Y+1]);
		}
		if((X+1 < h) && (Y >= 1) && grid[X+1][Y-1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y-1]);
		}
		if((X+1 < h) && grid[X+1][Y] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y]);
		}
		if((X+1 < h) && (Y+1 < w) && grid[X+1][Y+1] == char(65+1)) {
			dp[X][Y] = max(dp[X][Y],1+dp[X+1][Y+1]);
		}
		ans = max(dp[X][Y],ans);
	}
	cout << "Case " << t << ": " << ans << endl;
	return;
}


int main()
{
	t = 0;
    while(1) {
    	t++;
    	cin >> h >> w;
    	if((h == 0) && (w == 0)) break;
    	solve();
    }
    return 0;
}

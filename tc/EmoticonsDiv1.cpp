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

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

class EmoticonsDiv1
{
	ll dp[1005][1005];
	ll total;
public:
	ll solve(ll req,ll curCount) {
		if(req == 0) return 0;
		if(curCount >= 1005) return ( req < 0 ? (ll)(-1*req) : (ll)(INT_MAX));
		if(req < 0) return (ll)(-1*req);
		if(dp[req][curCount] != -1) return dp[req][curCount];
		dp[req][curCount] = INT_MAX;
		if(curCount != 0) dp[req][curCount] = 1 + solve(req - curCount, curCount);
		if((total - req) != curCount) dp[req][curCount] = min(dp[req][curCount],1+solve(req,total-req));
		if((total-req) > 0) dp[req][curCount] = min(dp[req][curCount],1+solve(req+1,curCount));
		return dp[req][curCount];
	}
	int printSmiles(int smiles) {
		fill(dp,-1);
		total = smiles;
		return (int)(solve(total-1,0));
	}
};
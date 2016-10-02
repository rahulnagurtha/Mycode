#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007

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

class DivFreed2
{
	int dp[11][100005];			// dp[i][j] = #ways to fill array of size i whose first element is j 
	VI divisors[100005];
public:
	int count(int n,int k) {
		fill(dp,0);
		int ans = 0,sum = 0;
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; i*j <= k; ++j) {
				divisors[i*j].pb(i);
			}
		}
		for (int i = 1; i <= k; ++i) {
			dp[1][i] = 1;
		}
		for (int sz = 2; sz <= n; ++sz) {
			sum = 0;
			for (int i = 1; i <= k; ++i) {
				sum += dp[sz-1][i];
				sum %= MOD;
			}
			for (int i = 1; i <= k; ++i) {
				dp[sz][i] = sum;
				for (int j = 0; j < divisors[i].size(); ++j) {
					if(divisors[i][j] != i) dp[sz][i] = rem((dp[sz][i] - dp[sz-1][divisors[i][j]]),MOD);
				}
			}
		}
		for (int i = 1; i <= k; ++i) {
			ans = (ans + dp[n][i])%MOD;
		}
		return ans;
	}
};
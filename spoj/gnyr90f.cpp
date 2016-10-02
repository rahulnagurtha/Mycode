#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

ll dp[110][110][2];

void init() {
	for (int i = 1; i <= 109; ++i) {
		dp[0][i][0] = 0;
		dp[0][i][1] = 0;
	}
	dp[0][0][0] = 1;
	dp[0][0][1] = 1;
	for (int i = 1; i <= 109; ++i) {
		dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
		dp[i][0][1] = dp[i-1][0][0];
	}
	for (int i = 1; i <= 109; ++i) {
		for (int j = 1; j <= 109; ++j) {
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
		}
	}
	return;
}

ll calculate(ll n,ll k) {
	ll ans = 0;
	ans += dp[n-1][k][1] + dp[n-1][k][0];
	return ans;
}

int main()
{
	init();
	int t;
	si(t);
	while(t--) {
    	ll temp,n,k;
    	slli3(temp,n,k);
        printf("%lld %lld\n",temp,calculate(n,k));
	}
    return 0;
}

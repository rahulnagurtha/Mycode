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
#define plli(i)                 printf("%lld\n",i)

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


int dp[12][225][225];



void preprocess() {					//dp[i][j][k] = dp[i][j][k+1] + dp[i-1][j-k][k]
	fill(dp,0);
	for (int i = 1; i < 225; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[1][i][j] = 1;
		}
	}
	for (int i = 2; i < 11; ++i) {
		for (int j = 1; j < 225; ++j) {
			for (int k = j - 1; k > 0; --k) {
				dp[i][j][k] = dp[i][j][k+1] + dp[i-1][j-k][k];
			}
		}
	}
	return;
}


void print(int m,int n,int k,int lft) {
	int tmp = 0;
	for (int i = lft; i <= m; ++i) {
		if( (tmp + dp[n][m][i] - dp[n][m][i+1]) >= k) {
			cout << i << " ";
			if(n > 1) print(m-i,n-1,k - (tmp),i);
			return;
		}
		else tmp += dp[n][m][i] - dp[n][m][i+1];
	}
}


int main()
{
    ll t;
    preprocess();
    cin >> t ;
    while(t--) {
    	int m,n,k;
    	cin >> m >> n >> k;
    	print(m,n,k,1);
    	printf("\n");
    }
    return 0;
}

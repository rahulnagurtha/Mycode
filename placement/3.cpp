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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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


ll n,m;
ll c[1005][1005];
ll p[1005][1005];
ll dp[2][1005][1005]; //0 for down,1 for right


inline void Refresh() {
    
}


int main()
{
    ll t;
    // freopen("in.txt", "r", stdin);
    slli(t);
    while(t--) {
        Refresh();
        slli2(n,m);
        for (ll i = 1; i <= n; ++i) {
        	for (ll j = 1; j <= m; ++j) {
        		slli(c[i][j]);
        	}
        }
        for (ll i = 1; i <= n; ++i) {
        	for (ll j = 1; j <= m; ++j) {
        		slli(p[i][j]);
        	}
        }
        dp[0][n][m] = dp[1][n][m] = c[n][m];
        
        //fill rightmost column
        for (ll i = n - 1; i > 0; --i) {
        	dp[0][i][m] = c[i][m] + dp[0][i+1][m];
        	dp[1][i][m] = p[i][m] + dp[0][i][m];
        }
        //fill bottomMost row
        for (ll i = m-1; i > 0; --i) {
        	dp[1][n][i] = c[n][i] + dp[1][n][i+1];
        	dp[0][n][i] = p[n][i] + dp[1][n][i];
        }
        for (ll j = m - 1; j > 0; --j) {
        	for (ll i = n - 1; i > 0; --i) {
        		dp[0][i][j] = c[i][j] + min(dp[0][i+1][j],p[i][j] + dp[1][i][j+1]);
        		dp[1][i][j] = c[i][j] + min(dp[1][i][j+1],p[i][j] + dp[0][i+1][j]);
        	}
        }
        plli(min(dp[0][1][1],dp[1][1][1]));
    }
    return 0;
}
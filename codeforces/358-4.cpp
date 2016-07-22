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
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

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


string s,t;
ll n,m,kk;
ll dp[1005][1005][11];


int main()
{
    cin >> n >> m >> kk;
    cin >> s ;
    cin >> t;
    // fill(dp,-1);
    if(s[1] == t[1]) dp[1][1][1] = 1;
    else dp[1][1][1] = 0;

    for (ll j = 2; j <= m; ++j) {
    	if(s[1] == t[j]) dp[1][j][1] = 1;
    	else dp[1][j][1] = dp[1][j-1][1];
    }

    for (ll j = 2; j <= n; ++j) {
    	if(s[j] == t[1]) dp[j][1][1] = 1;
    	else dp[j][1][1] = dp[j-1][1][1];
    }

    for (ll i = 2; i <= n; ++i) {
    	for (ll j = 2; j <= m; ++j) {
    		for (ll k = 1; k <= kk; ++k) {
    			if (s[i] != t[j]) {
    				dp[i][j][k] = max(dp[i][j-1][k],dp[i-1][j][k]);
    			}
    			else {
    				dp[i][j][k] = max(1+dp[i-1][j-1][k-1],1+dp[i-1][j-1][k]);	
    			}
    		}
    	}
    }
    cout << dp[n][m][kk] << endl;


    return 0;
}

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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll dp[1005][1005];

int main()
{
    int t;
    si(t);
    while(t--) {
    	ll n,m,s;
    	ll a[1005];
    	fill(dp,0);
    	slli3(n,m,s);
    	for (int i = 1; i <= m; ++i) {
    		slli(a[i]);
    	}
    	dp[s][0] = 1;
    	for (int i = 1; i <= m; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			if(j-a[i] >= 1) dp[j-a[i]][i] = rem(dp[j-a[i]][i]+dp[j][i-1],MOD);
    			if(j+a[i] <= n) dp[j+a[i]][i] = rem(dp[j+a[i]][i]+dp[j][i-1],MOD);
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		printf("%lld ",dp[i][m]);
    	}
    	printf("\n");
    }
    return 0;
}

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
#define MOD                     100000000

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

int dp[2][201][101][101];
int n1,n2,k1,k2;

int solve(int parity,int foot,int horse,int past) {
	if(dp[parity][foot][horse][past] != -1) return dp[parity][foot][horse][past];
	if(foot == 0 && horse == 0) return (dp[parity][foot][horse][past] = 1); 
	dp[parity][foot][horse][past] = 0;
	if(parity == 0) {
		if(horse > 0) dp[parity][foot][horse][past] = solve(1,foot,horse-1,1);
		if(past < k1 && foot > 0) dp[parity][foot][horse][past] += solve(0,foot-1,horse,past+1);
		dp[parity][foot][horse][past] %= MOD;
	}
	else {
		if(foot > 0) dp[parity][foot][horse][past] = solve(0,foot-1,horse,1);
		if(past < k2 && horse > 0) dp[parity][foot][horse][past] += solve(1,foot,horse-1,past+1);
		dp[parity][foot][horse][past] %= MOD;
	}
	return dp[parity][foot][horse][past];
}

int main()
{
    fill(dp,-1);
    cin >> n1 >> n2 >> k1 >> k2;
    cout << (solve(0,n1,n2,0))%MOD << endl;
    return 0;
}
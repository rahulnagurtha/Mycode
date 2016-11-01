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
#define INF 					INT_MAX
#define N                     	50007


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



ll ans;
ll n,k;
VI adjList[N];
ll dp[505][N];


void dfs(int cur,int par) {
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(adjList[cur][i] != par) {
			dfs(adjList[cur][i],cur);
		}
	}
	dp[0][cur] = 1;
	for (int j = 1; j <= 500; ++j) {
		for (int i = 0; i < adjList[cur].size(); ++i) {
			if(adjList[cur][i] != par) {
				dp[j][cur] += dp[j-1][adjList[cur][i]];
			}
		}
	}
	ans += dp[k][cur];
	ll tmp = 0;
	for (int lft = 1; lft < k; ++lft) {
		for (int i = 0; i < adjList[cur].size(); ++i) {
			if(adjList[cur][i] != par) {
				tmp += (dp[lft - 1][adjList[cur][i]])*(dp[k-lft][cur] - dp[k - lft - 1][adjList[cur][i]]);
			}
		}
	}
	ans += tmp/2;
	return;
}


int main()
{
	ll u,v;
	slli2(n,k);
	for (ll i = 1; i < n; ++i) {
		slli2(u,v);
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	dfs(1,-1);
	plli(ans);
    return 0;
}
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
#define N                     	100007
#define LOGN                    20


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

VOII edges;
int val[N];
int depth[N];
VI adjList[N];
int dp[LOGN][N];
map<PII,int> cnt;

void dfsPassOne(int cur,int parent,int d = 0) {
	dp[0][cur] = parent;
	depth[cur] = d;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(parent != adjList[cur][i]) {
			dfsPassOne(adjList[cur][i],cur,d + 1);
		}
	}
	return;
}

void dfsPassTwo(int cur,int parent) {
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(parent != adjList[cur][i]) {
			dfsPassTwo(adjList[cur][i],cur);
		}
	}
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(parent != adjList[cur][i]) {
			val[cur] += val[adjList[cur][i]];
			cnt[mp(min(cur,adjList[cur][i]),max(cur,adjList[cur][i]))] += val[adjList[cur][i]];
		}
	}
	return;
}

int lca(int u,int v) {
	if(depth[u] > depth[v]) swap(u,v);
	int diff = depth[v] - depth[u];
	int tmp = 1,cnt = 0;
	while(tmp <= diff) {
		if(tmp & diff) {
			v = dp[cnt][v];
		}
		cnt++;
		tmp = tmp << 1;
	}
	if(u == v) return u;
	for (int i = LOGN - 1; i >= 0; --i) {
		if(dp[i][u] != dp[i][v]) {
			u = dp[i][u];
			v = dp[i][v];
		}
	}
	return dp[0][u];
}

int main()
{
	int n,k;
	int u,v;
	si(n);
	for (int i = 1; i < n; ++i) {
		si2(u,v);
		adjList[u].pb(v);
		adjList[v].pb(u);
		edges.pb(mp(u,v));
	}
	fill(dp,-1);
	dfsPassOne(1,-1);
	for (int i = 1; i < 18; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(dp[i-1][j] != -1) dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	si(k);
	for (int i = 0; i < k; ++i) {
		si2(u,v);
		val[u]++;val[v]++;
		val[lca(u,v)] -= 2;
	}
	dfsPassTwo(1,-1);
	for (int i = 0; i < n - 1; ++i) {
		printf("%d ",cnt[mp(min(edges[i].FF,edges[i].SS),max(edges[i].FF,edges[i].SS))]);
	}
	printf("\n");
    return 0;
}
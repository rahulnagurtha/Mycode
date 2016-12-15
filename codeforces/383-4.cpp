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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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
#define N                     	1007


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






inline void Refresh() {
    
}

ll n,m,w;
VL adj[N];
ll weight[N];
ll beauty[N];
ll dp[N][N];
VOLL moota[N];
bool visited[N];
ll totalComp;

ll recurse(ll maxWeight,ll till) {
	if(till == 0) return 0;
	if(dp[maxWeight][till] != -1) return dp[maxWeight][till];
	dp[maxWeight][till] = 0;
	for (int i = 0; i < moota[till].size(); ++i) {
		if(maxWeight >= moota[till][i].FF) {
			ll tmp = moota[till][i].SS + recurse(maxWeight - moota[till][i].FF,till-1);
			dp[maxWeight][till] = max(dp[maxWeight][till],tmp);
		}
	}
	dp[maxWeight][till] = max(dp[maxWeight][till],recurse(maxWeight,till-1));
	return dp[maxWeight][till];
}

void dfs(ll cur,ll comp) {
	moota[comp].pb(mp(weight[cur],beauty[cur]));
	visited[cur] = true;
	for (int i = 0; i < adj[cur].size(); ++i) {
		ll nxt = adj[cur][i];
		if(!visited[nxt]) {
			dfs(nxt,comp);
		}
	}
}

void process() {
	fill(dp,-1);
	for (ll i = 1; i <= totalComp; ++i) {
		ll wtSum = 0;
		ll beautySum = 0;
		for (int j = 0; j < moota[i].size(); ++j) {
			wtSum += moota[i][j].FF;
			beautySum += moota[i][j].SS;
		}
		moota[i].pb(mp(wtSum,beautySum));
		// cout << moota[i] << endl;
	}
	return;
}

int main()
{
	ll u,v;
	slli3(n,m,w);
	
	// cin >> n >> m >> w;
	for (int i = 1; i <= n; ++i) {
		slli(weight[i]);
		// cin >> weight[i];
	}
	for (int i = 1; i <= n; ++i) {
		slli(beauty[i]);
		// cin >> beauty[i];
	}
	for (int i = 0; i < m; ++i) {
		slli2(u,v);
		// cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			totalComp++;
			dfs(i,totalComp);
		}
	}
	process();
	plli(recurse(w,totalComp));
	// cout << recurse(w,totalComp) << endl;
    return 0;
}
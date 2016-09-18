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
#define MAX_NODES               1005
#define LOGN                    12



typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

VOVI graph;
bool isRoot[MAX_NODES];
int dp[MAX_NODES][LOGN+1],depth[MAX_NODES];


void init() {
	graph.clear();
	graph.resize(MAX_NODES);
	fill(depth,0);
	fill(isRoot,true);
	fill(dp,-1);
}

void dfs(int cur,int par,int parDepth) {
	dp[cur][0] = par;
	depth[cur] = parDepth + 1;
	for (int i = 0; i < graph[cur].size(); ++i) {
		dfs(graph[cur][i],cur,depth[cur]);
	}
	return;
}

int lca(int u,int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	int tmp = 1,cnt = 0;
	while(tmp <= diff) {
		if(tmp & diff) {
			u = dp[u][cnt];
		}
		cnt++;
		tmp = tmp << 1;
	}
	if(u == v) return u;
	for (int i = LOGN; i >= 0; --i) {
		if(dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

int main()
{
	SYNC;
    int t,cnt = 1;
    cin >> t ;
    while(t--) {
    	int n,tmp,u,v;
    	int numChildren,numQueries;
    	init();
    	cin >> n;
    	for (int i = 0; i < n; ++i) {
    		cin >> numChildren;
    		for (int j = 0; j < numChildren; ++j) {
    			cin >> tmp;
    			graph[i+1].pb(tmp);
    			isRoot[tmp] = false;
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		if(isRoot[i]) {
    			dfs(i,-1,-1);
    			break;
    		}
    	}
    	for (int j = 1; j <= LOGN; ++j) {
    		for (int i = 1; i <= n; ++i) {
    			if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
    		}
    	}
    	cout << "Case " << cnt << ":" << endl;
    	cin >> numQueries;
    	for (int i = 0; i < numQueries; ++i) {
    		cin >> u >> v;
    		cout << lca(u,v) << endl;
    	}
    	cnt++;
    }
    return 0;
}

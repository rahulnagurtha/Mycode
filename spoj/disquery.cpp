#include <bits/stdc++.h>

using namespace std;

#define root 					1
#define N 						100010
#define LN 						18
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)

typedef long long int 		ll;
typedef pair<int,int> 		PII;
typedef vector<int> 		VI;
typedef vector<ll> 			VL;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

int u,v,c;
int q,n,lca;
PII lft,ryt;
int par[LN][N],depth[N];
int maX[LN][N],miN[LN][N];

vector <int> adj[N],cost[N];

void init() {
	fill(par,-1);
	fill(maX,-1);
	for (int i = 0; i < LN; ++i) {
		for (int j = 0; j < N; ++j) {
			miN[i][j] = INT_MAX;
		}
	}
	return;
}

void preprocess() {
	for (int i = 1; i < LN; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(par[i-1][j] != -1) par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	for (int i = 1; i < LN; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(par[i-1][j] != -1) miN[i][j] = min(miN[i-1][j],miN[i-1][par[i-1][j]]);
		}
	}
	for (int i = 1; i < LN; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(par[i-1][j] != -1) maX[i][j] = max(maX[i-1][j],maX[i-1][par[i-1][j]]);
		}
	}
	return;
}

void dfs(int cur,int pre,int price,int _depth = 0) {
	depth[cur] = _depth;
	par[0][cur] = pre;
	miN[0][cur] = price;
	maX[0][cur] = price;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if(adj[cur][i] != pre) {
			dfs(adj[cur][i],cur,cost[cur][i],_depth+1);
		}
	}
	return;
}

int LCA(int u,int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	int tmp = 1,cnt = 0;
	while(tmp <= diff) {
		if(diff & tmp) u = par[cnt][u];
		tmp = tmp << 1;
		cnt++;
	}
	if(u == v) return u;
	for (int i = LN - 1; i >= 0; --i) {
		if(par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

PII query_up(int u,int v) {
	int diff = depth[u] - depth[v];
	int tmp = 1,cnt = 0;
	int retMin = INT_MAX, retMax = -1;
	while(tmp <= diff) {
		if(diff & tmp) {
			retMax = max(retMax,maX[cnt][u]);
			retMin = min(retMin,miN[cnt][u]);
			u = par[cnt][u];
		}
		cnt++;
		tmp = tmp << 1;
	}
	return mp(retMin,retMax);
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d",&u,&v,&c);
		adj[u].pb(v);
		adj[v].pb(u);
		cost[u].pb(c);
		cost[v].pb(c);
	}
	init();
	dfs(root,-1,-1);
	preprocess();
	scanf("%d",&q);
	for (int i = 0; i < q; ++i) {
		scanf("%d %d",&u,&v);
		lca = LCA(u,v);
		lft = ryt = mp(INT_MAX,-1);
		lft = query_up(u,lca);
		ryt = query_up(v,lca);
		printf("%d %d\n",min(lft.FF,ryt.FF),max(lft.SS,ryt.SS));
	}
    return 0;
}
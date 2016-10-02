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
#define MAX_NODES               10005
#define LOGN                    15



typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

vector<VOII> graph;
bool visited[MAX_NODES];
int dp[MAX_NODES][LOGN+1];
int edgeSum[MAX_NODES],depth[MAX_NODES];



void init() {
	graph.clear();
	graph.resize(MAX_NODES);
	fill(depth,0);
    fill(edgeSum,0);
	fill(visited,false);
	fill(dp,-1);
}

void dfs(int cur,int par,int parDepth,int sumFromRoot) {
	visited[cur] = true;
    dp[cur][0] = par;
	edgeSum[cur] = sumFromRoot;
    depth[cur] = parDepth + 1;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(!visited[graph[cur][i].FF]) {
            dfs(graph[cur][i].FF,cur,parDepth + 1,sumFromRoot + graph[cur][i].SS);
	    }
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

int findkthAncestor(int node,int k) {
    int tmp = 1,cnt = 0;
    while(tmp <= k) {
        if(tmp & k) node = dp[node][cnt]; 
        cnt++;
        tmp = tmp << 1;
    }
    return node;
}


int main()
{
	SYNC;
    int t,cnt = 1;
    cin >> t ;
    while(t--) {
    	int n,u,v,w,node,tmp;
    	int numChildren,numQueries;
        int edgesU2Node,edgesV2Node;
        string queryType;
    	init();
    	cin >> n;
    	for (int i = 1; i < n; ++i) {
    		cin >> u >> v >> w;
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
    	}
		dfs(1,-1,-1,0);
    	for (int j = 1; j <= LOGN; ++j) {
    		for (int i = 1; i <= n; ++i) {
    			if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
    		}
    	}
    	while(1) {
            cin >> queryType;
            if (queryType == "DONE") break;
            else if(queryType == "DIST") {
                cin >> u >> v;
                cout << edgeSum[u] + edgeSum[v] - 2*edgeSum[lca(u,v)] << endl;
            }
            else {
                cin >> u >> v >> w;
                node = lca(u,v);
                edgesU2Node = depth[u]- depth[node];
                edgesV2Node = depth[v]- depth[node];
                if(w <= edgesU2Node + 1) {
                    cout << findkthAncestor(u,w - 1) << endl;
                }
                else cout << findkthAncestor(v,edgesU2Node + edgesV2Node + 1 - w) << endl;
            }
        }
    	cnt++;
    }
    return 0;
}

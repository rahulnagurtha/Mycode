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
#define INF                     100000000000007LL
#define N                       100007
#define LOGN                    18


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

int n,m;
int depth[N];
VI adjList[N];
ll fromhere[N]; 
ll st[LOGN][N];
int dp[LOGN][N];
VOII tickets[N];	//cost,power


void dfs(int cur,int par,int curDepth) {
	dp[0][cur] = par;
	depth[cur] = curDepth;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(adjList[cur][i] != par) dfs(adjList[cur][i],cur,curDepth+1);
	}
	return;
}

void preprocess() {
	for (int i = 0; i < N; ++i) {
		fromhere[i] = INF;
	}
	fromhere[1] = 0;
	for (int j = 1; (1 << j) < n; ++j) {
		for (int i = 1; i <= n; i++) {
			if(dp[j-1][i] != -1) dp[j][i] = dp[j-1][dp[j-1][i]];
		}
	}
	return;
}


void initialise() {
	fill(dp,-1);
}

void dfs_pass_two(int cur,int par) {
	// cout << "processing " << cur << "<>" ;
	if(tickets[cur].size() != 0) {
		int nodesAbove = depth[cur];
		// cout << nodesAbove ;
		for (int i = 0; i < tickets[cur].size(); ++i) {
			if(tickets[cur][i].SS >= nodesAbove) {
				fromhere[cur] = min(fromhere[cur],(ll)tickets[cur][i].FF);
			}
			else {
				ll curMin = INF;
				int j = tickets[cur][i].SS;
				int u = dp[0][cur];
				int tmp = 1,cnt = 0;
				while(tmp <= j) {
					if(tmp & j) {
						curMin = min(curMin,st[cnt][u]);
						u = dp[cnt][u];
					}
					cnt++;
					tmp = tmp << 1;
				}
				fromhere[cur] = min((ll)tickets[cur][i].FF + curMin,fromhere[cur]);
			}
		}
	}
	// printf(" cost is %lld\n",fromhere[cur]);
	// printf("\n");
	st[0][cur] = fromhere[cur];
	for (int i = 1; (1 << i) <= n; ++i) {
		if(dp[i-1][cur] != -1) st[i][cur] = min(st[i-1][cur],st[i-1][dp[i-1][cur]]);
		else st[i][cur] = st[i-1][cur];
	}
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(adjList[cur][i] != par) dfs_pass_two(adjList[cur][i],cur);
	}
	return;
}

int main()
{
    initialise();
    int q;
    int u,v;
    int k,w;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
    	cin >> u >> v;
    	adjList[u].pb(v);
    	adjList[v].pb(u);
    }
    dfs(1,-1,0);
    preprocess();
    for (int i = 0; i < m; ++i) {
    	cin >> v >> k >> w;
    	tickets[v].pb(mp(w,k));
    }
    for (int i = 0; i < adjList[1].size(); ++i) {
    	dfs_pass_two(adjList[1][i],1);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
    	cin >> u;
    	cout << fromhere[u] << endl; 
    }
    return 0;
}
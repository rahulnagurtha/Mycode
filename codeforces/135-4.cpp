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
#define N                     	200007


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

VOII adjList[N];
int totalRedEdges;
int green[N];
int red[N];

bool cmp(PII lft,PII ryt) {
	//cost,vertex
	if(lft.FF != ryt.FF) return lft.FF < ryt.FF;
	else return lft.SS < ryt.SS;
}

void dfs(int cur,int par,int redEdges,int greenEdges) {
	green[cur] = greenEdges;
	red[cur] = redEdges;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(adjList[cur][i].FF != par) {
			totalRedEdges += (adjList[cur][i].SS + 1) % 2;
			dfs(adjList[cur][i].FF,cur,redEdges + (adjList[cur][i].SS+1)%2,greenEdges + adjList[cur][i].SS);
		}
	}
	return;
}



int main()
{
	VI Q;
    int n;
    int u,v;
    int ans = INT_MAX;
    si(n);
    for (int i = 1; i < n; ++i) {
    	si2(u,v);
    	adjList[u].pb(mp(v,1));
    	adjList[v].pb(mp(u,0));
    }
    dfs(1,-1,0,0);
    for (int i = 1; i <= n; ++i) {
    	ans = min(ans,green[i] + totalRedEdges - red[i]);
    }
    for (int i = 1; i <= n; ++i) {
    	if(ans == green[i] + totalRedEdges - red[i]) Q.pb(i);
    }
    printf("%d\n",ans);
    for (int i = 0; i < Q.size(); ++i) {
    	printf("%d ",Q[i]);
    }
    printf("\n");
    return 0;
}
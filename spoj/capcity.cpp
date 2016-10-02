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
#define N                     	100007
#define M                     	200007

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

VI adjList[N];
VI rAdjList[N];
bool visited[N];
stack<int> order;
VI ans;

void dfs1(int cur) {
	visited[cur] = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(!visited[adjList[cur][i]]) dfs1(adjList[cur][i]);
	}
	order.push(cur);
	return;
}

void dfs2(int cur) {
	visited[cur] = true;
	ans.pb(cur);
	for (int i = 0; i < rAdjList[cur].size(); ++i) {
		if(!visited[rAdjList[cur][i]]) dfs2(rAdjList[cur][i]);
	}
	return;
}

int main()
{
    int n,m;
    int u,v;
    si2(n,m);
    for (int i = 0; i < m; ++i) {
    	si2(u,v);
    	adjList[u].pb(v);
    	rAdjList[v].pb(u);
    }
    fill(visited,false);
    for (int i = 1; i <= n; ++i) {
    	if(!visited[i]) {
    		dfs1(i);
    	}
    }
    fill(visited,false);
    while(!order.empty()) {
    	if(!visited[order.top()]) {
    		ans.clear();
    		dfs2(order.top());
    	}
    	order.pop();
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
    	printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
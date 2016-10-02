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
#define N                     	5007

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

VI ans;
VI layer[N];
VI graph[N];
VI adjList[N];
VI rAdjList[N];
bool visited[N];
stack<int> order;
bool visitedTwo[N];

void initialise() {
    for (int i = 0; i < N; ++i) {
        layer[i].clear();
        graph[i].clear();
        adjList[i].clear();
        rAdjList[i].clear();
    }
    ans.clear();
    return;
}

void dfsZero(int cur,int cnt) {
    visited[cur] = true;
    layer[cnt].pb(cur);
    for (int i = 0; i < graph[cur].size(); ++i) {
        if(!visited[graph[cur][i]]) dfsZero(graph[cur][i],cnt);
    }
    return;
}

void dfsOne(int cur) {
	visited[cur] = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(!visited[adjList[cur][i]]) dfsOne(adjList[cur][i]);
	}
	order.push(cur);
	return;
}

void dfsTwo(int cur) {
	visitedTwo[cur] = true;
	ans.pb(cur);
	for (int i = 0; i < rAdjList[cur].size(); ++i) {
		if(!visitedTwo[rAdjList[cur][i]]) dfsTwo(rAdjList[cur][i]);
	}
	return;
}

int main()
{
    while(1) {
        initialise();
        int n,m;
        int u,v;
        int cmpnts = 0;
        VI finalans;
        si(n);
        if(n == 0) break;
        si(m);
        for (int i = 0; i < m; ++i) {
        	si2(u,v);
        	adjList[u].pb(v);
        	rAdjList[v].pb(u);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        fill(visited,false);
        for (int i = 1; i <= n; ++i) {
            if(!visited[i]) {
                dfsZero(i,cmpnts);
                cmpnts++;
            }           
        }
        for (int i = 0; i < cmpnts; ++i) {
            fill(visited,false);
            for (int j = 0; j < layer[i].size(); ++j) {
                if(!visited[layer[i][j]]) {
                    dfsOne(layer[i][j]);
                }
            }
            fill(visitedTwo,false);
            while(!order.empty()) {
                if(!visitedTwo[order.top()]) {
                    ans.clear();
                    dfsTwo(order.top());
                }
                order.pop();
            }
            for (int j = 0; j < ans.size(); ++j) {
                finalans.pb(ans[j]);
            }
        }
        sort(finalans.begin(),finalans.end());
        for (int i = 0; i < finalans.size(); ++i) {
        	if(i != 0) printf(" ");
            printf("%d",finalans[i]);
        }
        printf("\n");
    }
    return 0;
}
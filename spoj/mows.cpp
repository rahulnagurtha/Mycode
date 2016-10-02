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
#define N                     	101007

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


int h,p,s;
int cnt,idx;
VI adjList[N];
VI rAdjList[N];
bool visited[N];
stack<int> order;

void dfs1(int cur) {
	visited[cur] = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(!visited[adjList[cur][i]]) dfs1(adjList[cur][i]);
	}
	order.push(cur);
	return;
}

void dfs2(int cur) {
    if(cur > 1000) cnt++;
    else idx = min(idx,cur);
	visited[cur] = true;
	for (int i = 0; i < rAdjList[cur].size(); ++i) {
		if(!visited[rAdjList[cur][i]]) dfs2(rAdjList[cur][i]);
	}
	return;
}

void initialise() {
    for (int i = 0; i < N; ++i) {
        adjList[i].clear();
        rAdjList[i].clear();
    }
    return;
}

int main()
{
    int t;
    si(t);
    while(t--) {
        initialise();
        int u,v;
        int ans = 0;
        int finalIdx = INT_MAX;
        si3(h,p,s);
        for (int i = 0; i < s; ++i) {
        	si2(u,v);
        	adjList[u].pb(v);
        	rAdjList[v].pb(u);
        }
        fill(visited,false);
        for (int i = 1; i <= h; ++i) {
        	if(!visited[i]) {
        		dfs1(i);
        	}
        }
        for (int i = 1001; i <= 1000+p; ++i) {
            if(!visited[i]) {
                dfs1(i);
            }
        }
        fill(visited,false);
        while(!order.empty()) {
        	if(!visited[order.top()]) {
        		cnt = 0;
                idx = INT_MAX;
        		dfs2(order.top());
                if(cnt > ans && idx <= 1000) {
                    ans = cnt;
                    finalIdx = idx;
                }
                else if(cnt == ans && idx < finalIdx) {
                    finalIdx = idx;
                }
        	}
        	order.pop();
        }
        printf("%d %d\n",finalIdx,ans);
    }
    return 0;
}
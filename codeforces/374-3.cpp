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

ll T,n,m;
VL ans;
VOLL adjList[5005];
int data[5005][5005];

void dfs_pass_one(ll cur,VL &path,ll timeSoFar) {
	if(cur == n) {
		if(ans.size() < path.size() && timeSoFar <= T) ans = path;
		return;
	}
	if(timeSoFar > T) return;
	if(timeSoFar >= data[cur][path.size() - 1]) return;
	data[cur][path.size() - 1] = (int)(timeSoFar);
	for (int i = 0; i < adjList[cur].size(); ++i) {
		path.pb(adjList[cur][i].FF);
		dfs_pass_one(adjList[cur][i].FF,path,timeSoFar + adjList[cur][i].SS);
		path.pop_back();
	}
	return;
}

int main()
{
	for (int i = 0; i < 5005; ++i) {
		for (int j = 0; j < 5005; ++j) {
			data[i][j] = INT_MAX;
		}
	}
	ll u,v,c;
    slli3(n,m,T);
    for (ll i = 0; i < m; ++i) {
    	slli3(u,v,c);
    	adjList[u].pb(mp(v,c));
    }
    VL tmp;
    tmp.pb(1);
    dfs_pass_one(1,tmp,0);
    plli(ll(ans.size()));
    for (int i = 0; i < ans.size(); ++i) {
    	printf("%I64d ",ans[i]);
    }
    return 0;
}
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
#define INF                     INT_MAX
#define N                       100007


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

int n;
bool isThereEdge[1005][1005];
bool visited[1005];
int colour[1005];
bool isBipartite;

void dfs(int cur,int curColour) {
	// printf("%d->",cur);
	visited[cur] = true;
	colour[cur] = curColour;
	for (int i = 1; i <= n; ++i) {
		if(cur == i) continue;
		if(isThereEdge[cur][i]) {
			if(!visited[i]) dfs(i,(curColour+1)%2);
			else {
				if(colour[i] == curColour) isBipartite = false;
			}
		} 
	}
	return;
}

int main()
{
	fill(isThereEdge,true);
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	fill(colour,-1);
    	fill(visited,false);
    	isBipartite = true;
    	VOII edges;
        int m;
        int u,v;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
        	cin >> u >> v;
        	edges.pb(mp(u,v));
        	isThereEdge[u][v] = false;
        	isThereEdge[v][u] = false;
        }
        for (int i = 1; i <= n; ++i) {
        	if(!visited[i]) {
        		dfs(i,0);
        		// printf("\n");
        	}
        }
        if(isBipartite) printf("YES\n");
        else printf("NO\n");
        for (int i = 0; i < m; ++i) {
        	isThereEdge[edges[i].FF][edges[i].SS] = true;
        	isThereEdge[edges[i].SS][edges[i].FF] = true;
        }
    }
    return 0;
}
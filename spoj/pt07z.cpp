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

int f[10005],g[10005];
VI graph[10005];

void dfs(int cur,int pre) {
	f[cur] = 0;
	g[cur] = 0;
	int fHighest = -1,sHighest = -1;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(graph[cur][i] != pre) {
			dfs(graph[cur][i],cur);
			f[cur] = max(f[cur],f[graph[cur][i]]);
			if(f[graph[cur][i]] >= fHighest) {
				sHighest = fHighest;
				fHighest = f[graph[cur][i]];
			}
			else if(f[graph[cur][i]] >= sHighest) {
				sHighest = f[graph[cur][i]];
			}
		}
	}
	f[cur]++;
	g[cur] = 1 + max(0,fHighest) + max(0,sHighest);
	return;
}


int main()
{
    int n,u,v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	cin >> u >> v;
    	graph[u].pb(v);
    	graph[v].pb(u);
    }
    fill(f,-1);
    fill(g,-1);
    dfs(1,-1);
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
    	ans = max(ans,max(f[i],g[i]));
    }
    cout << ans-1 << endl;
    return 0;
}

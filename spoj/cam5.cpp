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
#define N 						100005

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

VI graph[N];
bool visited[N];
int cmp;

void init() {
	for (int i = 0; i < N; ++i) {
		graph[i].clear();
	}
	cmp = 0;
	fill(visited,false);
	return;
}

void dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(!visited[graph[cur][i]]) {
			dfs(graph[cur][i]);
		}
	}
	return;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
    	init();
    	int n,e,u,v;
    	cin >> n >> e;
    	for (int i = 0; i < e; ++i) {
    		cin >> u >> v;
    		graph[u].pb(v);
    		graph[v].pb(u);
    	}
    	for (int i = 0; i < n; ++i) {
    		if(!visited[i]) {
    			cmp++;
    			dfs(i);
    		}
    	}
    	cout << cmp << endl;
    }
    return 0;
}
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

int dp[2][N];
VI adjList[N];


void dfs(int cur,int par) {
	int sumOne = 0;
	int sumZero = 0;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(adjList[cur][i] != par) {
			dfs(adjList[cur][i],cur);
			sumZero += dp[0][adjList[cur][i]];
			sumOne += dp[1][adjList[cur][i]];
		}
	}
	dp[0][cur] = min(1 + sumZero,sumOne);
	dp[1][cur] = 1 + sumZero;
	return;
}

int main()
{
    int n;
    int u,v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	cin >> u >> v;
    	adjList[u].pb(v);
    	adjList[v].pb(u);
    }
    dfs(1,-1);
    cout << min(dp[0][1],dp[1][1]) << endl;
    return 0;
}
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





VI adjList[N];
int color[N];
bool isBipartite;
bool visited[N];


void dfs(int cur,int curColor) {
	visited[cur] = true;
	color[cur] = curColor;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if (!visited[adjList[cur][i]]) {
			dfs(adjList[cur][i],(curColor + 1) % 2);
		}
		else if(color[adjList[cur][i]] == curColor) {
			isBipartite = false;
		}
	}
	return;
}


int main()
{
	fill(color,-1);
	isBipartite = true;
	int n,m;
	int u,v;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		if(!visited[i]) dfs(i,0);
	}
	if (!isBipartite) {
		cout << "-1" << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) cnt++;
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) cout << i << " ";
	}
	cout << endl;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 1) cnt++;
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 1) cout << i << " ";
	}
    return 0;
}
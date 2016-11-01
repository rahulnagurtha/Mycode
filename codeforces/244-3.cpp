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



ll n,m;
ll cost[N];
stack<ll> T;
VL adjList[N];
VL rAdjList[N];
bool visited[N];
PLL component[N]; //min,count


void init() {
	for (int i = 0; i < N; ++i) {
		component[i].FF = INT_MAX;
		component[i].SS = 0;
	}
	return;
}


void dfsPassOne(ll cur) {
	int nxt;
	visited[cur] = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		nxt = adjList[cur][i];
		if(!visited[nxt]) dfsPassOne(nxt);
	}
	T.push(cur);
	return;
}

void dfsPassTwo(ll cur,ll idx) {
	int nxt;
	visited[cur] = true;
	if(component[idx].FF == cost[cur]) component[idx].SS++;
	else if(component[idx].FF > cost[cur]) {
		component[idx].FF = cost[cur];
		component[idx].SS = 1;
	}
	for (int i = 0; i < rAdjList[cur].size(); ++i) {
		nxt = rAdjList[cur][i];
		if(!visited[nxt]) dfsPassTwo(nxt,idx);
	}
	return;
}


int main()
{
	init();
	ll u,v;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		adjList[u].pb(v);
		rAdjList[v].pb(u);
	}
	for (int i = 1; i <= n; ++i) {
		if(!visited[i]) dfsPassOne(i);
	}
	fill(visited,false);
	ll cnt = 0;
	while(!T.empty()) {
		if(!visited[T.top()]) {
			cnt++;
			dfsPassTwo(T.top(),cnt);
		}
		T.pop();
	}
	cout << endl;
	ll totalCost = 0;
	ll numWays = 1;
	for (int i = 0; i < N; ++i) {
		if(component[i].FF != INT_MAX) {
			totalCost += component[i].FF;
			numWays *= component[i].SS;
			numWays %= MOD;
		}
	}
	cout << totalCost << " " << numWays << endl;
    return 0;
}
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
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
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

inline ll rem(ll a, ll b) {
	if(a<0) return (a%b+b)%b;
	else return a%b;
}



ll n,m,components,cnt;
ll fac[100005],ans;
ll power[10];
bool cycle,degree_conflict;

map<ll,VL> graph;
map<ll,bool> visited;
map<ll,ll> parent;
deque<ll> Q;
VL vertices;
VOLL edges;





void preprocess() {
	fac[0] = power[0] = 1;
	for (ll i = 1; i < 100005; ++i) fac[i] = (fac[i-1]*i) % MOD;
	for (ll i = 1; i < 10; ++i) power[i] = power[i-1]*2;
	return;
}




void flush_the_shit() {
	cnt = 0;
	components = 0;
	cycle = false;
	degree_conflict = false;
	graph.clear();
	visited.clear();
	parent.clear();
	vertices.clear();
	return;
}



void add_edge(ll idx) {
	graph[edges[idx].FF].pb(edges[idx].SS);
	graph[edges[idx].SS].pb(edges[idx].FF);
	parent[edges[idx].FF] = edges[idx].FF;
	parent[edges[idx].SS] = edges[idx].SS;
	visited[edges[idx].FF] = false;
	visited[edges[idx].SS] = false;
	vertices.pb(edges[idx].FF);
	vertices.pb(edges[idx].SS);
	return;
}



void dfs(ll cur) {
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(!visited[graph[cur][i]]) {
			parent[graph[cur][i]] = cur;
			dfs(graph[cur][i]);
		}
		else if(parent[cur] != graph[cur][i]) cycle = true;
	}
	return;
}


int main()
{
	preprocess();
	int t;
	cin >> t;
	while(t--) {
		edges.clear();
		ll a,b,ans = 0,tmp;
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if(a == b) continue;
			edges.pb(mp(a,b));
		}
		m = edges.size();
		for (ll i = 0; i < (1 << m); ++i) {
			flush_the_shit();
			for (ll j = 0; j < m; ++j) {
				if(i & (1 << j)) {
					cnt++;
					add_edge(j);
				}
			}
			for (auto it = graph.begin(); it != graph.end(); ++it) {
				if(it->second.size() > 2) {
					degree_conflict = true;
					break;
				}
			}
			if(degree_conflict) continue;	
			for (int j = 0; j < vertices.size(); ++j) {
				if(!visited[vertices[j]]) {
					components++;
					dfs(vertices[j]);
				}
			}
			if(cycle) continue;
			tmp = power[components]*fac[n-graph.size()+components];
			if(cnt % 2 == 1) tmp = tmp*(-1);
			ans = rem(ans + rem(tmp,MOD), MOD);
		}
		cout << ans << endl;
	}
    return 0;
}

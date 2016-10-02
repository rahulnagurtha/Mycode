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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll n;
ll a[100005];
ll val[100005];
bool visitedPass1[100005];
bool visitedPass2[100005];
bool mark[100005];
ll longendhere[100005];
ll p,c;
ll ans;


vector<vector<PLL> > graph(100005);

void dfs2(ll ver) {
	visitedPass2[ver] = true;
	if(!mark[ver]) return;
	ans++;
	for (int i = 0; i < graph[ver].size(); ++i) {
		if(!visitedPass2[graph[ver][i].FF]) {
			dfs2(graph[ver][i].FF);
		}
	}
	return;
}


void dfs1(ll par,ll ver,ll weight) {
	visitedPass1[ver] = true;
	longendhere[ver] = max(0LL,max(weight,weight + longendhere[par]));
	for (int i = 0; i < graph[ver].size(); ++i) {
		if(!visitedPass1[graph[ver][i].FF]) {
			dfs1(ver,graph[ver][i].FF,graph[ver][i].SS);
		}
	}
	return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> val[i];
    }
    for (int i = 1; i < n; ++i) {
    	cin >> p >> c;
    	graph[i+1].pb(mp(p,c));
    	graph[p].pb(mp(i+1,c));
    }
    longendhere[1] = 0;
    visitedPass1[1] = true;
    for (int i = 0; i < graph[1].size(); ++i) {
		if(!visitedPass1[graph[1][i].FF]) {
			dfs1(1,graph[1][i].FF,graph[1][i].SS);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if(val[i] >= longendhere[i]) mark[i] = true;
		//cout << longendhere[i] << " "; 
	}
	//printf("\n");
	dfs2(1);
	ans = n - ans;
	cout << ans << endl;
    return 0;
}

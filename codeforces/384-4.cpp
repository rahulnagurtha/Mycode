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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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
#define N                     	200007


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


ll n;
ll a[N];
VL adjList[N];
bool isPossible;
ll ans;

void preProcess(ll cur,ll par) {
	for (ll i = 0; i < adjList[cur].size(); ++i) {
		ll nxt = adjList[cur][i];
		if(nxt != par) {
			preProcess(nxt,cur);
			a[cur] += a[nxt];
		}
	}
	return;
}

ll dfs(ll cur,ll par) {
	VL tmp;
	ll max_in_this = a[cur];
	for (ll i = 0; i < adjList[cur].size(); ++i) {
		ll nxt = adjList[cur][i];
		if(nxt != par) tmp.pb(dfs(nxt,cur));
	}
	if(tmp.size() > 0) {
		sort(tmp.begin(), tmp.end());
		max_in_this = max(tmp.back(),max_in_this);
	}
	if(tmp.size() > 1) {
		isPossible = true;
		ll max_pair_sum = tmp.back();
		tmp.pop_back();
		max_pair_sum += tmp.back();
		ans = max(ans,max_pair_sum);
	}
	return max_in_this;
}



int main()
{
	ll u,v;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (ll i = 1; i < n; ++i) {
		cin >> u >> v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	isPossible = false;
	ans = MOD*(10000000LL)*(-1);
	preProcess(1,-1);
	dfs(1,-1);
	if(!isPossible) cout <<	"Impossible" << endl;
	else cout << ans << endl;
    return 0;
}
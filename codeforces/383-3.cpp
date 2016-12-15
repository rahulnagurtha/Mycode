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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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





ll nxt[105];
ll dist[105];
bool visited[105];
VL A;


void dfs(ll cur,ll dis) {
	dist[cur] = dis;
	if(visited[cur]) {
		return;
	}
	visited[cur] = true;
	if(dis == INF) dfs(nxt[cur],1);
	else dfs(nxt[cur],dis+1);
}


ll lcm() {
	ll res = 1;
	for (ll i = 0; i < A.size(); i++) {
		res = res*A[i]/__gcd(res,A[i]);
	}
	return res;
}

int main()
{
	
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; ++i) {
		cin >> nxt[i];
	}
	for (ll i = 0; i < 105; ++i) {
		dist[i] = INF;
	}
	for (ll i = 1; i <= n; ++i) {
		if(!visited[i]) {
			dfs(i,INF);
			if(dist[i] == INF) {
				cout << "-1" << endl;
				return 0;
			}
			if(dist[i] % 2 == 0) A.pb(dist[i]/2);
			else A.pb(dist[i]);
		}
	}
	cout << lcm() << endl;
    return 0;
}
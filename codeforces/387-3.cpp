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






inline void Refresh() {
    
}

ll n,q;
ll t,k,d;
VOLL a;
VOLL aux;
VL ans;
VOLL servers;

int main()
{
	slli2(n,q);
	for (int i = 1; i <= n; ++i) {
		a.pb(mp(i,0));
	}
	for (ll tt = 0; tt < q; ++tt) {
		ll sum = 0;
		slli3(t,k,d);
		for (int i = 0; i < a.size(); ++i) {
			if(a[i].SS < t) a[i].SS = t - 1;
		}
		sort(a.begin(), a.end());
		aux.clear();
		servers.clear();
		for (int i = 0; i < a.size(); ++i) {
			if(a[i].SS < t && servers.size() < k) {
				servers.pb(a[i]);
			}
			else aux.pb(a[i]);
		}
		if(servers.size() < k) {
			sum = -1;
			for (int i = 0; i < servers.size(); ++i) {
				aux.pb(servers[i]);
			}
		}
		else {
			sum = 0;
			for (int i = 0; i < servers.size(); ++i) {
				sum += servers[i].FF;
				servers[i].SS = t + d - 1;
				aux.pb(servers[i]);
			}
		}
		ans.pb(sum);
		a = aux;
	}
	for (int i = 0; i < ans.size(); ++i) {
		plli(ans[i]);
	}
    return 0;
}
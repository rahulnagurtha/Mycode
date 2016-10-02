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


inline void Refresh() {
    
}


ll n;
ll a[N];
ll p[N];
ll lft[N];
ll sum[N];
ll ryt[N];
VL final;

int main()
{
	fill(lft,-1);
	fill(ryt,-1);
	slli(n);
	for (ll i = 1; i <= n; ++i) {
		slli(a[i]);
	}
	for (ll i = 1; i <= n; ++i) {
		slli(p[i]);
	}
	a[0] = 0;
	a[n + 1] = 0;
	lft[0] = 0;
	ryt[0] = 0;
	lft[n + 1] = n + 1;
	ryt[n + 1] = n + 1;
	ll ans = 0;
	for (ll i = n; i > 0; --i) {
		final.pb(ans);
		ll tmp = a[p[i]];
		//process p[i]
		if(lft[p[i] - 1] != -1 && ryt[p[i] + 1] != -1) {
			tmp += sum[p[i] - 1] + sum[p[i] + 1];
			sum[lft[p[i] - 1]] = tmp;
			sum[ryt[p[i] + 1]] = tmp;
			ryt[lft[p[i] - 1]] = ryt[p[i] + 1];
			lft[ryt[p[i] + 1]] = lft[p[i] - 1];
			ans = max(ans,tmp);
		}
		else if(lft[p[i] - 1] != -1) {
			lft[p[i]] = lft[p[i] - 1];
			ryt[p[i]] = p[i];
			tmp += sum[p[i] - 1];
			sum[lft[p[i] - 1]] = tmp;
			sum[p[i]] = tmp;
			ryt[lft[p[i] - 1]] = p[i];
			ans = max(ans,tmp);
		}
		else if(ryt[p[i] + 1] != -1) {
			lft[p[i]] = p[i];
			ryt[p[i]] = ryt[p[i] + 1];
			tmp += sum[p[i] + 1];
			sum[ryt[p[i] + 1]] = tmp;
			sum[p[i]] = tmp;
			lft[ryt[p[i] + 1]] = p[i];
			ans = max(ans,tmp);
		}
		else {
			lft[p[i]] = p[i];
			ryt[p[i]] = p[i];
			sum[p[i]] = a[p[i]];
			ans = max(ans,tmp);
		}
	}
	for (int i = final.size() - 1; i >= 0; --i) {
		plli(final[i]);
	}
    return 0;
}
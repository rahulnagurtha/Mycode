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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

ll s[1500005],t[1500005],a[1500005];
ll n,m;

void init() {
	a[0] = 0;
	for (int i = 1; i <= n; ++i) s[i] = (78901 + 31*s[i-1])%699037;
	for (int i = 1; i <= n; ++i) t[i] = (23456 + 64*t[i-1])%2097151;
	for (int i = 1; i <= n; ++i) a[i] = (ll)(s[i]%100 + 1)*(ll)(t[i]%100 + 1);
	return;
}

void calculate() {
	ll Qsum = 0;
	ll tocheck = n;
	ll ans = n,tmp = 0;
	ll ryt = 1;
	for (ll i = n; i >= 1; --i) {
		tmp += a[i];
		if(tmp > m) break;
		tocheck = i-1;
	}
	for (ll i = 1; i <= tocheck; ++i) {
		if(a[i] > m) {
			ans = 0;
			break;
		}
		Qsum = Qsum-a[i-1];
		if(i-1 != ryt-1) {
			Qsum = Qsum-a[ryt-1];
			ryt--;
		}
		while(1) {
			if(Qsum + a[ryt] <= m) {
				Qsum += a[ryt];
				ryt++;
			}
			else break;
		}
		ans = min(ryt-i,ans);
	}
	ans = min(ans,n-tocheck+1);
	printf("%d\n",ans);
	return;
}

int main()
{
    int test;
    si(test);
    while(test--) {
    	slli2(s[0],t[0]);
    	slli2(n,m);
    	init();
    	calculate();
    }
    return 0;
}

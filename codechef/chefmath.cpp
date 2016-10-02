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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

VL fib;
map<pair<ll,PLL>,ll> data;

void precompute() {
	int a,b,tmp;
	a = 1;
	b = 2;
	fib.pb(a);
	while(b <= 1000000000) {
		fib.pb(b);
		tmp = b;
		b = b + a;
		a = tmp;
	}
	return;
}


ll recurse(ll target,ll till,ll chances) {
	// if (data.find(mp(target,mp(till,chances))) != data.end()) {
		// return data[mp(target,mp(till,chances))];
	// }
	if(chances*fib[till] < target) return 0;
	ll ans = 0;
	if(target == fib[till]) {
		if (chances == 1) ans++;
		if (till > 0) ans += recurse(target,till-1,chances);
	}
	else if (target - fib[till] < 0) {
		if (till > 0) ans += recurse(target,till-1,chances);
	}
	else {
		if (chances > 1) ans += recurse(target - fib[till],till,chances-1);
		if(till > 0) ans += recurse(target,till-1,chances);
	}
	ans = ans%MOD;
	// data[mp(target,mp(till,chances))] = ans;
	return ans;
}


int main()
{
	precompute();
    int t;
    cin >> t ;
    while(t--) {
    	ll x,k;
    	cin >> x >> k;
    	cout << recurse(x,fib.size()-1,k) << endl;
    }
    return 0;
}

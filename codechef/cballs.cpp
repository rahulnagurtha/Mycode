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
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
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

int a[10002],n;
VI primes;

void sieve() {
	bool prime[10001];
	for (int i = 0; i < 10001; ++i) prime[i] = true;
	prime[2] = true;
	for (int i = 2; i < 10001; ++i) {
		if(!prime[i]) continue;
		primes.pb(i);
		for (int j = i; j < 10001; j += i) prime[j] = false;
	}
	return;
}


int main()
{
	sieve();
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int ans = 0,tmp = 2000000000,tmp1;
    	cin >> n;
    	for (ll i = 0; i < n; ++i) cin >> a[i];
    	for (ll i = 1; i < n; ++i) {
    		if(a[i] < a[i-1]) {
    			ans = ans + a[i-1] - a[i];
    			a[i] = a[i-1];
    		}
    	}
    	for (int i = 0; i < primes.size(); ++i) {
    		tmp1 = 0;
    		for (int j = 0; j < n; ++j) {
    			if(a[j]%primes[i] != 0)
    			tmp1 = tmp1 + (primes[i] - a[j] % primes[i]);
    		}
    		tmp = min(tmp,tmp1);
    	}
    	ans = ans + tmp;
    	cout << ans << endl;

    }
    return 0;
}

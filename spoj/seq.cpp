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
#define MOD                     1000000000LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



ll b[15],c[15],k,n;



void fastexp() {
	ll tmp[15][15],T[15][15],tmp1[15][15],n1 = n - 1;
	ll ans = 0;
	fill(tmp,0);
	fill(T,0);
	for (ll i = 0; i < 15; ++i) {
		tmp[i][i] = 1;
	}
	for (ll i = 0; i < k - 1; ++i) {
		T[i][1+i] = 1;
	}
	for (ll i = 0; i < k; ++i) {
		T[k-1][i] = c[k-1-i];
	}
	while(n1 > 0) {
		if(n1%2 == 1) {	// multiply to the answer
			for (ll i = 0; i < k; ++i) {
				for (ll j = 0; j < k; ++j) {
					tmp1[i][j] = 0;
					for (int l = 0; l < k; ++l) {
						tmp1[i][j] += tmp[i][l]*T[l][j];
						tmp1[i][j] %= MOD;
					}
				}
			}
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < k; ++j) {
					tmp[i][j] = tmp1[i][j];
				}
			}
		}
		//square the T-matrix
		for (ll i = 0; i < k; ++i) {
			for (ll j = 0; j < k; ++j) {
				tmp1[i][j] = 0;
				for (int l = 0; l < k; ++l) {
					tmp1[i][j] += T[i][l]*T[l][j];
					tmp1[i][j] %= MOD;
				}
			}
		}
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < k; ++j) {
				T[i][j] = tmp1[i][j];
			}
		}
		n1 /= 2;
	}
	for (ll i = 0; i < k; ++i) {
		ans = ans + (tmp[0][i]*b[i]) % MOD;
		ans = ans % MOD;
	}
	cout << ans << endl;
	return;
}



int main()
{
    ll t;
    cin >>t;
    while(t--) {
    	cin >> k;
    	for (ll i = 0; i < k; ++i) {
    		cin >> b[i];
    	}
    	for (ll i = 0; i < k; ++i) {
    		cin >> c[i];
    	}
    	cin >> n;
    	fastexp();
    }
    return 0;
}
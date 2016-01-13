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


ll tmp,m,base;
ll power[200003];

ll fastexp(ll a,ll b) {
	ll ans = 1;
	while(b > 0) {
		if(b%2 == 1) ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b = b >> 1;
	}
	return ans;
}

bool alleven() {
	for (int i = 0; i < 200001; ++i) {
		if(power[i] % 2 == 1) return false;
	}
	return true;
}

int main()
{
	ll ans = 1;
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	cin >> tmp;
    	power[tmp]++;
    }
    if(alleven()) {
    	base = 1;
    	for (ll i = 0; i < 200001; ++i) {
    		if(power[i] > 0) {
    			for (ll j = 0; j < power[i]; j += 2) {
    				base = (base*i)%MOD;
    			}
    		}
    	}
    	for (int i = 0; i < 200001; ++i) {
    		if(power[i] == 0) continue;
    		base = fastexp(base,power[i]+1);
    	}
    	ans = base;
    }
    else {
    	base = 1;
    	for (ll i = 0; i < 200001; ++i) {
    		if(power[i] > 0) {
    			for (ll j = 0; j < power[i]; j++) {
    				base = (base*i)%MOD;
    			}
    		}
    	}
    	int i = 0;
    	for (; i < 200001; ++i) {
    		if(power[i] == 0) continue;
    		if(power[i]%2 == 1) {
	    		base = fastexp(base,(power[i]+1)/2);    			
    			i++;
    			break;
    		}
    		base = fastexp(base,power[i]+1);
    	}
    	for (; i < 200001; ++i) {
    		if(power[i] == 0) continue;
    		base = fastexp(base,power[i]+1);
    		
    	}
    	ans = base;
    }
    cout << ans << endl;
    return 0;
}

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


ll fast_exp[18];


ll sigDigit(ll input)
{
    ll digits =  log10(input) + 1;
    return input /fast_exp[digits-1];
}

ll trimlast(ll a) {
	ll digits =  log10(a) + 1;
	return a - sigDigit(a)*(fast_exp[digits-1]) ;
}

ll retsum(ll a) {
	ll ans = 0;
	if(a == 0) return 0;
	ll digits = log10(a) + 1;
	ll sig = sigDigit(a);
	if(digits >= 2) ans = (digits-1)*45*sig*(fast_exp[digits-2]) + (fast_exp[digits-1])*( (sig*(sig-1))/2);
	else ans = (sig*(sig+1))/2;
	return ans;

}

ll calc(ll a) {
	if(a <= 0) return 0;
	ll ans = 0;
	ll digits = log10(a) + 1;
	ll sig = sigDigit(a);
	ll last = trimlast(a);
	if(digits ==  1) return (a*(a+1))/2;
	ans +=  retsum(sig*fast_exp[digits-1]) + sig*(last+1) + calc(last);
	return ans;
}

int main()
{
	fast_exp[0] = 1;
	for (int i = 1; i < 18; ++i) fast_exp[i] = (10LL)*fast_exp[i-1];
    while(1) {
    	ll a,b;
    	cin >> a >> b;
    	if(a == -1 && b == -1) break;
    	cout << calc(b) - calc(a-1)<< endl; 
    }
    return 0;
}

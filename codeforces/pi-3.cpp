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

ll n,k;
ll a[200005];
map<ll,ll> lft;
map<ll,ll> ryt;
ll ans;

int main()
{
	slli2(n,k);
	for (ll i = 1; i <= n; ++i) {
		slli(a[i]);
		if(i < 2) lft[a[i]]++;
		else ryt[a[i]]++;
	}
	for (ll i = 2; i < n; ++i) {
		ryt[a[i]]--;
		if(a[i]%k == 0) ans += lft[a[i]/k]*ryt[a[i]*k];
		lft[a[i]]++;
	}
	plli(ans);
    return 0;
}
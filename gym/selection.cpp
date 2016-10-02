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


ll numEven(ll l,ll r) {
	if(l%2 == 1) l++;
	if(r%2 == 1) r--;
	if(l > r) return 0;
	return 1 + (r - l)/2;
}

ll numOdd(ll l,ll r) {
	if(l%2 == 0) l++;
	if(r%2 == 0) r--;
	if(l > r) return 0;
	return 1 + (r - l)/2;
}

int main()
{
	SYNC;
    ll n;
    ll ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
    	if(i%2 == 0) {
    		ans += ((numEven(i + 1,n)*(numEven(i + 1,n) - 1)))/2;
    		ans += ((numOdd(i + 1,n)*(numOdd(i + 1,n) - 1)))/2;
    	}
    	else {
    		ans += numEven(i + 1,n)*numOdd(i + 1,n);
    	}
    }
    cout << ans << endl;
    return 0;
}
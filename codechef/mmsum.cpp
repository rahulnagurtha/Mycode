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

ll a[100005],n;
ll tilHereL[100005];
ll tilHereR[100005];

int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	ll ans = MOD,tmp;
    	ans = ans*(-1);
    	cin >> n;
    	tilHereL[0] = tilHereL[n+1] = 0;
    	tilHereR[0] = tilHereR[n+1] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 1; i <= n; ++i) {
    		tilHereL[i] = max(tilHereL[i-1]+a[i],a[i]);
    	}
    	for (int i = n; i >= 1; --i) {
    		tilHereR[i] = max(tilHereR[i+1]+a[i],a[i]);
    	}
    	for (int i = 1; i <= n; ++i) {
    		tmp = a[i] + max(0LL,tilHereL[i-1]) + max(0LL,tilHereR[i+1]);
    		if(i > 1 && i < n) tmp = max(tmp,max(tilHereL[i-1] + max(0LL,tilHereR[i+1]),max(0LL,tilHereL[i-1]) + tilHereR[i+1]));
    		else if(i == 1) {
    			tmp = max(tmp,tilHereR[i+1]);
    		}
    		else {
    			tmp = max(tmp,tilHereL[i-1]);
    		}
    		ans = max(ans,tmp);
    	}
    	cout << ans << endl;
    }
    return 0;
}
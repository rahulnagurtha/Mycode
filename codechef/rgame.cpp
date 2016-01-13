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



ll po[100005];
ll a[100005];
ll pre[100005];


int main()
{
	po[0] = 1;
	for (int i = 1; i < 100005; ++i) {
		po[i] = po[i-1]*2;
		po[i] %= MOD;
	}
    int t;
    cin >> t ;
    while(t--) {
    	int n;
    	ll sum = 0;
    	cin >> n;
    	for (int i = 1; i <= n + 1; ++i) {
    		cin >> a[i];
    	}
    	pre[2] = a[1]*2;
    	pre[2] %= MOD;
    	for (int i = 3; i <= n + 1; ++i) {
    		pre[i] = pre[i-1] + po[i-2]*a[i-1];
    		pre[i] %= MOD;
    	}

    	for (int i = 2; i <= n + 1; ++i) {
    		sum = sum*2;
    		sum %= MOD;
    		sum += pre[i]*a[i];
    		sum %= MOD;
    	}
    	cout << sum << endl;
    }
    return 0;
}

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

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};



int main()
{
    ll t;
    ll n,u,q;
    slli(t);
    while(t--) {
    	ll idx;
    	ll l,r,val;
    	ll toremove[10005] = {0};
    	ll a[10005];
    	ll sum = 0;
    	slli2(n,u);
    	for (int i = 0; i < u; ++i) {
    		slli3(l,r,val);
    		l++;
    		r++;
    		sum += val;
    		toremove[r] += val;
    		if(l != 1) {
    			toremove[l-1] = toremove[l-1] - val;
    			sum -= val;
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		a[i] = sum;
    		sum = sum - toremove[i];
    	}
    	slli(q);
    	for (int i = 0; i < q; ++i) {
    		slli(idx);
    		plli(a[idx+1]);
    	}
    }
    return 0;
}

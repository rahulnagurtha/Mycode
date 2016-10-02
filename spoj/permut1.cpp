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


ll dp[4096][100];

void init() {
	fill(dp,-1);
	dp[0][0] = 1;
	for (int i = 1; i < 100; ++i) dp[0][i] = 0;
	return;
}

ll state(ll mask,ll inv) {
	if(dp[mask][inv] != -1) return dp[mask][inv];
	VI numbers;
	int tmp = 1;
	for (int i = 0; i < 12; ++i) {
		if(tmp & mask) numbers.pb(i);
		tmp = tmp << 1;
	}
	// if(mask == 15) cout << numbers << endl;
	dp[mask][inv] = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		if(inv >= (numbers.size()-i-1)) {
			// if(mask == 15) printf("%d\n",i);
			dp[mask][inv] += state(mask - (1 << numbers[i]),inv - (numbers.size()-i-1));
		}
	}
	return dp[mask][inv];
}


int main()
{
	init();
    int t;
    si(t);
    while(t--) {
    	ll n,k;
    	slli2(n,k);
    	plli(state((1 << n)-1,k));
    }
    return 0;
}

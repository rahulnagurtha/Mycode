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
#define lmt						1000000000000000LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll power[60];
ll sum[60];

void init() {
	sum[0] = 0;
	power[0] = 0;
	power[1] = 2;
	sum[1] = 2;
	for (int i = 2; i < 50; ++i) power[i] = (power[i-1] << 1);
	for (int i = 2; i < 60; ++i) {
		sum[i] = sum[i-1] + power[i];
		if(sum[i] > lmt) break;
	}
	return;
}

PLL findtuple(ll tmp) {
	PLL ans; //length,number
	for (int i = 1; i < 60; ++i) {
		if(sum[i] >= tmp) {
			ans.FF = i;
			ans.SS = tmp-sum[i-1];
			return ans;
		}
	}
}



int main()
{
	init();
	int n;
	si(n);
	while(n--) {
		ll k;
		slli(k);
		PLL tmp = findtuple(k);
		while(1) {
			if(tmp.FF == 1) {
				if(tmp.SS == 1) printf("5");
				else printf("6");
				break;
			}
			if(power[tmp.FF - 1] < tmp.SS) {
				printf("6");
				tmp.SS = tmp.SS - power[tmp.FF-1];
				tmp.FF = tmp.FF-1;
			}
			else {
				printf("5");
				tmp.FF = tmp.FF-1;
			}
		}
		printf("\n");
	}    
    return 0;
}

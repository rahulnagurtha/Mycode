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

ll w,m;

int main()
{
    VI inRange;
    ll tmp = 1;
    cin >> w >> m;
    if(m == 1) {
    	printf("YES\n");
    	return 0;
    }
    if(m%2 == 0) {
    	printf("NO\n");
    	return 0;
    }
    m = (m - 1)/2;
    if(w == 2) {
    	printf("YES\n");
    	return 0;
    }
    while(tmp <= m) {
    	inRange.pb(tmp);
    	tmp *= w;
    }
    ll till = 1 << inRange.size();
    for (ll i = 0; i < till; ++i) {
    	int tmpSum = 0;
    	for (int j = 0; j < inRange.size(); ++j) {
    		if((1LL << j) & i) {
    			tmpSum += inRange[j];
    		}
    	}
    	if(tmpSum == m) {
    		printf("YES\n");
    		return 0;
    	}
    }
    printf("NO\n");
    return 0;
}
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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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
#define N                     	1000007


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
ll a[N];
int dp[10*N];


bool isAchievable(ll target) {
	ll soFar = 0;
	for (int i = 0; i < 10*N; ++i) {
		if(i < target) dp[i] = 0;
		else dp[i] = max(1,dp[i/2] + dp[i - i/2]);
	}
	for (int i = 1; i <= n; ++i) {
		soFar += dp[a[i]];
	}
	return (soFar >= k);
}


int main()
{
	bool isPossible = false;
	ll answer = -1;
	ll lft = 1;
	ll ryt = 10000000LL;
	slli2(n,k);
	for (int i = 1; i <= n; ++i) {
		slli(a[i]);
	}
	while(lft <= ryt) {
		ll mid = (lft + ryt + 1)/2;
		if(isAchievable(mid)) {
			isPossible = true;
			answer = mid;
			lft = mid + 1;
		}
		else ryt = mid - 1;
	}
	if(!isPossible) {
		printf("-1\n");
	}
	else {
		plli(answer);
	}
    return 0;
}
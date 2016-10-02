#include <bits/stdc++.h>

using namespace std;


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
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



LL dp[251][51],coins[51],n,m,ans;

void init() {
	fill(dp,-1);
	ans = 0;
	return;
}

LL instance(LL target,LL from) {
	if(target < 0) return 0;
	if(target == 0) return dp[target][from] = 1;
	if(dp[target][from] != -1) return dp[target][from];
	dp[target][from] = 0;
	for (LL i = from; i < m; ++i) {
		dp[target][from] += instance(target-coins[i],i);
	}
	return dp[target][from];
}

int main()
{
	init();
    slli2(n,m);
    for (LL i = 0; i < m; ++i) {
    	slli(coins[i]);
    }
    sort(coins,coins+m);
    for (LL i = 0; i < m; ++i) {
    	ans += instance(n-coins[i],i);
    }
    plli(ans);
    return 0;
}
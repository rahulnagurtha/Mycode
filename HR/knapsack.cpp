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


LL dp[2001][2001],n,k,weight[2001];


void init() {
	fill(dp[0],0);
	for (int i = 0; i <= n; ++i) dp[i][0] = 0;
	return;
}

LL knapsack() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if(j - weight[i] >= 0) {
				dp[i][j] = max(dp[i-1][j],weight[i] + dp[i][j-weight[i]]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		init();
	    slli2(n,k);
	    for (int i = 1; i <= n; ++i)
	    {
	    	slli(weight[i]);
	    }
	    plli(knapsack());
	}
    return 0;
}
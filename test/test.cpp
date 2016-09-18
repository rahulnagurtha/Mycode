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
#define INF                     INT_MAX
#define N                       3007


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
ll dp[N][N];
ll dp_[N][N];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp[1][a[1]] = 1;
    for (int i = 1; i <= N; ++i) {
    	dp_[1][i] = dp_[1][i-1] + dp[1][i];
    }
    for (int i = 2; i <= n; ++i) {
    	dp[i][a[i]]++;
    	for (int j = 1; j < i; ++j) {
    		if(a[i] + a[j] <= k && a[j] < a[i]) {
    			dp[i][a[i] + a[j]] += dp[j][k-a[i]];
    			dp[i][a[i] + a[j]] %= MOD;
    		}
    	}
    	for (int j = 1; j <= N; ++j) {
    		dp_[i][j] = dp_[i][j-1] + dp[i][j];
    		dp_[i][j] %= MOD;
    	}
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
		ans += dp_[i][k];
		ans %= MOD;	
    }
    cout << ans << endl;
    return 0;
}
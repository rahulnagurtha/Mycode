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

int dp[1001][1001],a[1001];
int pre[1001];


int main()
{
    while(1) {
    	int n;
    	cin >> n;
    	if(n == 0) break;
    	pre[0] = 0;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    		pre[i] = pre[i-1] + a[i];
    	}
    	for (int i = 1; i + 1 <= n; i++) {
    		dp[i][i+1] = max(a[i],a[i+1]);
    	}
    	for (int i = 4; i <= n; i = i + 2) {
    		//left
    		for (int j = 1; j + i - 1 <= n; j++) {
    			dp[j][j+i-1] = max(a[j] + ( (a[j+1] >= a[j+i-1]) ? dp[j+2][j+i-1] : dp[j+1][j+i-2]),a[j+i-1] + ( (a[j] >= a[j+i-2]) ? dp[j+1][j+i-2] : dp[j][j+i-3]) );
    		}
    	}
    	cout << 2*dp[1][n] - pre[n] << endl;
    }
    return 0;
}

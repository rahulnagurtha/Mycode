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


string a;
int dp[205],zero[205],one[205];
int n;

void solve() {
	dp[0] = zero[0] = one[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if(a[i] == '0') {
			zero[i] = zero[i-1] + 1;
			one[i] = one[i-1];
		}
		else {
			zero[i] = zero[i-1];
			one[i] = one[i-1] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if(zero[i] < one[i]) dp[i] = i;
		else dp[i] = 0;	
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i-1; j >= 1; --j) {
			if(zero[i] - zero[j] < one[i] - one[j]) {
				dp[i] = max(dp[i],dp[j] + i - j);
			}
			else dp[i] = max(dp[i],dp[j]);
		}
	}
	printf("%d\n",dp[n]);
	return;
}


int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	a = ' ';
    	string tmp;
    	cin >> n >> tmp;
    	a += tmp;
    	solve();
    }
    return 0;
}

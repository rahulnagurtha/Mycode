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


int n,a[200005],dp[200005];
ll ans;

int main()
{
	int tmp = 1000000007;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		tmp = min(a[i],tmp);
	}
	ans = ((ll)tmp)*((ll)n);
	for (int i = 0; i < n; ++i) {
		if(a[i] == tmp) a[i] = 0;
		else a[i] = 1;
	}

	fill(dp,0);
	if(a[n-1] == 0) dp[n-1] = 0;
	else dp[n-1] = 1;
	for (int i = n-2; i >= 0; --i) {
		if(a[i] == 0) dp[i] = 0;
		else {
			dp[i] = dp[i+1] + 1;
		}
	}
	bool valid = true;
	for (int i = 0; i < n; ++i) {
		if(a[i] != 1) {
			valid = false;
			break;
		}
	}
	if(valid) {
		ans = ans + n;
		cout << ans << endl;
		return 0;
	}
	tmp = -1;
	for (int i = n-1; i >= 0; --i) {
		if(a[i] == 0) {
			tmp = i;
			break;
		}
	}
	for (int i = n-1; i > tmp; --i) {
		dp[i] += dp[0];
	}
	
	tmp = -1;
	for (int i = 0; i < n; ++i) {
		tmp = max(tmp,dp[i]);
	}
	ans = ans + tmp;
	cout << ans << endl;
    return 0;
}

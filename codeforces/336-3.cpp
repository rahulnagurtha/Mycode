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


int n;

VOII a;
int dp[100005];


int search(int lft,int ryt,int target) {
	assert(lft <= ryt);

	if(ryt - lft == 1) {
		if(a[lft].FF >= target ) return -1;
		if(a[ryt].FF >= target ) return lft;
		else return ryt;
	}
	if(lft == ryt) {
		if(a[lft].FF >= target) return -1;
		else return lft;
	}
	int mid = (lft+ryt)/2;
	if(a[mid].FF >= target) return search(lft,mid-1,target);
	else return search(mid,ryt,target);
}


int main()
{
	int tmp,one,two;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> one >> two;
    	a.pb(mp(one,two));
    }
    sort(a.begin(),a.end());
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
    	tmp = search(0,i-1,a[i].FF-a[i].SS);
    	if(tmp != -1) dp[i] = dp[tmp] + 1;
    	else dp[i] = 1;
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
    	ans = max(ans,dp[i]);
    }
    ans = ans + 1;
    cout << n + 1 - ans << endl;
    return 0;
}

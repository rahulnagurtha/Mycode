#include <bits/stdc++.h>

using namespace std;



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

ll n,q,k;
ll dp[100005],a[100005];

ll bin_search(ll l, ll r, ll k, ll n) {
	assert(l<=r);
	if(l==r) {
		if(l+k*l >= n) return l;
		else return -1;
	}

	ll mid = (l+r)/2;
	if(mid+k*mid >= n) return bin_search(l,mid,k,n);
	else return bin_search(mid+1,r,k,n);

}

int main()
{   
    dp[0] = 0;
    slli(n);
    for (ll i = 1; i <= n; ++i) {
    	slli(a[i]);
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; ++i) {
    	dp[i] += dp[i-1] + a[i];
    }
    slli(q);
    for (ll i = 0; i < q; ++i) {
    	slli(k);
    	ll p = bin_search(1, n, k, n);
    	assert(p != -1);
    	cout << dp[p] << "\n";

    }

    return 0;
}
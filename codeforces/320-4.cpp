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
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

ll a[200005],n,k,x,tans,ans;
ll cnt[35] = {0};
ll mul[12];
ll power[35];

inline void process(ll one) {
	ll tmp = 0;
	while(one > 0) {
		if(one % 2 != 0) cnt[tmp]++;
		one /= 2;
		tmp++;
	}
}

void solve() {
	ll tmp;
	ans = tans;
	for(int j = 0; j < n; ++j) {
		tmp = tans;
		for(int i = 0; i < 32; ++i) {
			if((power[i] & a[j]) && (cnt[i] == 1)) {
				tmp = tmp - power[i];
			}
		}
		// cout << tmp << " | " << a[j] * mul[k] << endl;
		tmp = ((tmp) | (a[j] * mul[k]));
		ans = max(ans,tmp);
	}
	// printf("\n");
	cout << ans << endl;
}

int main()
{
	tans =  0;
	power[0] = mul[0] = 1;
	for(int i = 1; i < 35; ++i) power[i] = power[i-1]*2;
    cin >> n >> k >> x;
	for(int i = 1; i < 12; ++i) mul[i] = mul[i-1]*x;
    for(int i = 0; i < n; ++i) {
    	cin >> a[i];
    	tans = (tans | a[i]);
    	process(a[i]);
    }
    // for(int i = 0; i < 10; ++i) {
    	// cout << cnt[i] << "->";
    // }
    // printf("\n");
    solve();
    return 0;
}
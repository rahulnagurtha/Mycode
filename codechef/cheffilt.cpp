#include <bits/stdc++.h>

using namespace std;


#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



ll dp[ (1 << 10) + 1][ (1 << 10) + 1],pre[100005];
ll cnt[ (1 << 10) + 1],n,ans,num;
VL distinct;
char s[15],temp[15];

inline void toint() {
	ll ret = 0;
	for (ll i = 0; i < 10; ++i) {
		ret = ret << 1;
		if(temp[i] == '+') ret++;
	}
	cnt[ret]++;
	return;
}

void init() {
	fill(cnt,0);
	fill(dp,0);
	distinct.clear();
	return;
}



void process() {
	for (ll i = 0; i < (1 << 10); ++i) {
		if(cnt[i] != 0) distinct.pb(i);
	}
	return;
}

int main()
{
	pre[0] = 1;
	for (ll i = 1; i < 100005; ++i) pre[i] = (pre[i-1]*2) % MOD;
    ll t;
    scanf("%lld",&t);
    while(t--) {
    	init();
    	scanf("%s",s);
		scanf("%lld",&n);
    	for (ll i = 0; i < n; ++i) {
    		scanf("%s",temp);
    		toint();
    	}
    	process();
    	dp[0][0] = pre[cnt[distinct[0]]-1];
    	dp[0][distinct[0]] += pre[cnt[distinct[0]]-1];
    	dp[0][distinct[0]] = dp[0][distinct[0]] % MOD;
    	for (ll i = 1; i < distinct.size(); ++i) {
    		for (ll j = 0; j < (1 << 10); ++j) {
    			dp[i][j] = ( (pre[cnt[distinct[i]]-1]*dp[i-1][j]) % MOD + (pre[cnt[distinct[i]]-1]*dp[i-1][j^distinct[i]]) % MOD ) % MOD;
    		}
    	}
    	num = 0;
    	for (ll i = 0; i < 10; ++i) {
    		num = num << 1;
    		if(s[i] == 'w') num++;
    	}
    	ans = dp[distinct.size()-1][num];
    	printf("%lld\n",ans);
    }
    return 0;
}

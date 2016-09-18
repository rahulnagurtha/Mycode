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


#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define N                       100007


typedef long long int ll;
typedef vector<ll> VL;



ll n,m,x;
VL bags[105];
ll weight[105];
ll colour[105];
ll dp[105][10005];


inline void Refresh() {
    fill(dp,-1);
    for (int i = 0; i < 105; ++i) {
    	bags[i].clear();
    }
    return;
}


ll solve(ll cur,ll leftOverSpace) {
	// cout << cur << " " << leftOverSpace << endl;
	if(cur == 0) return 0;
	if(dp[cur][leftOverSpace] != -1) return dp[cur][leftOverSpace];
	dp[cur][leftOverSpace] = INT_MIN;
	for (int i = 0; i < bags[cur].size(); ++i) {
		if(leftOverSpace >= bags[cur][i]) {
			ll tmp = solve(cur-1,leftOverSpace - bags[cur][i]);
			if(tmp >= 0) dp[cur][leftOverSpace] = max(dp[cur][leftOverSpace],bags[cur][i] + tmp);
		}
	}
	// cout << "dp[" << cur << "][" << leftOverSpace << "] = " << dp[cur][leftOverSpace] << endl;
	return dp[cur][leftOverSpace];
}


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    si(t);
    while(t--) {
    	Refresh();
        slli3(n,m,x);
        for (int i = 1; i <= n; ++i) {
        	slli(weight[i]);
        }
        for (int i = 1; i <= n; ++i) {
        	slli(colour[i]);
        }
        for (int i = 1; i <= n; ++i) {
        	bags[colour[i]].pb(weight[i]);
        }
        // for (int i = 1; i <= m; ++i) {
        // 	cout << bags[i] << endl;
        // }
        ll ans = solve(m,x);
        if(ans >= 0) printf("%lld\n",x - ans);
        else printf("-1\n");
    }
    return 0;
}
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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll dp[3][2005][2005];   //fire,water,air


ll s_time(ll health,ll armor,ll pos) {
	if((health <= 0) || (armor <= 0)) return 0;
	if(dp[pos][health][armor] != -1) return dp[pos][health][armor];
	ll ans = 0;
	if(pos == 0) ans = 1 + max(s_time(health-5,armor-10,1),s_time(health+3,armor+2,2));
	else if(pos == 1) ans = 1 + max(s_time(health-20,armor+5,0),s_time(health+3,armor+2,2));
	else ans = 1 + max(s_time(health-20,armor+5,0),s_time(health-5,armor-10,1));
	dp[pos][health][armor] = ans;
	return ans;
}

int main()
{
	fill(dp,-1);
    int t;
    cin >> t ;
    while(t--) {
    	ll h,a;
    	cin >> h >> a;
    	ll ans = max(s_time(h-20,a+5,0),max(s_time(h-5,a-10,1),s_time(h+3,a+2,2)));
    	cout << ans << endl;
    }
    return 0;
}

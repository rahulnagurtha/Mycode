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
#define N                       200007


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



inline void Refresh() {
    
}

int n;
int distinct[N];
map<int,int> info;
map<int,int> cnt;
int a[N];

int main()
{
	ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    distinct[n+1] = 0;
    for (int i = n; i >= 1; --i) {
    	info[a[i]]++;
    	if(info[a[i]] == 1) distinct[i] = distinct[i+1] + 1;
    	else distinct[i] = distinct[i+1];
    }
    for (int i = 1; i <= n; ++i) {
    	cnt[a[i]]++;
    	if(cnt[a[i]] == 1) ans += (distinct[i+1]);
    }
    cout << ans << endl;
    return 0;
}
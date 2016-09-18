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

VOII original;
set<int> info;
int cnt[N];
int a[N];

int main()
{
	ll ans = 0;
    int n,tmp;
    int cur = 2;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> tmp;
    	original.pb(mp(tmp,i));
    	info.insert(tmp);
    }
    sort(original.begin(),original.end());
    a[original[0].SS] = 1;
    for (int i = 1; i < n; ++i) {
    	if(original[i].FF != original[i-1].FF) {
    		a[original[i].SS] = cur;
    		cur++;
    	}
    	else a[original[i].SS] = cur-1;
    }
    int numDistint = 0;
    int lowerbound = 0,upperbound = 0;
    for (int i = 1; i <= n; ++i) {
    	while(numDistint < info.size() && lowerbound < n) {
    		lowerbound++;
    		cnt[a[lowerbound]]++;
	    	if(cnt[a[lowerbound]] == 1) numDistint++;
    	}
    	upperbound = max(upperbound,lowerbound);
    	while(upperbound < n) {
    		upperbound++;
    		if(cnt[a[upperbound]] == 0) {
    			upperbound--;
    			break;
    		}
    	}
    	if(numDistint == info.size()) ans += (upperbound - lowerbound + 1); 
    	cnt[a[i]]--;
    	if(cnt[a[i]] == 0) numDistint--;
    }
    cout << ans << endl;
    return 0;
}
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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	1000007


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

ll len[N];
VL sticks;


int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> len[i];
    }
    sort(len+1,len+n+1);
    ll lastlen = -1;
    for (int i = n; i > 0; --i) {
    	if(lastlen == -1) {
    		lastlen = len[i];
    		continue;
    	}
    	if(abs(len[i]-lastlen) <= 1) {
    		sticks.pb(min(len[i],lastlen));
    		lastlen = -1;
    	}
    	else lastlen = len[i];
    }
    reverse(sticks.begin(),sticks.end());
    for (int i = sticks.size() - 1; i >= 1; i -= 2) {
    	ans += sticks[i]*sticks[i-1];
    }
    cout << ans << endl;
    return 0;
}
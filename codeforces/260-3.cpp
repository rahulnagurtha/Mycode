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
#define N                     	100007


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


VOLL A;
ll n;
ll a[N];
ll dp[N];

ll recurse(int cur) {
	if(cur == 0) return 0;
	if(cur == 1) return A[cur].SS;
	if(dp[cur] != -1) return dp[cur];
	dp[cur] = 0;
	dp[cur] = max(recurse(cur-1),A[cur].SS + recurse( (A[cur].FF == A[cur-1].FF + 1 ? cur - 2 : cur-1) ));
	return dp[cur];
}


int main()
{
	fill(dp,-1);
    slli(n);
    for (int i = 0; i < n; ++i) {
    	slli(a[i]);
    }
    sort(a,a+n);
    A.pb(mp(-1,-1));
    for (int i = 0; i < n;) {
    	ll cur = a[i];
    	ll cnt = 0;
    	while(i < n && a[i] == cur) {
    		cnt++;
    		i++;
    	}
    	A.pb(mp(cur,cur*cnt));
    }
    // cout << A << endl;
    plli(recurse(A.size() - 1));
    return 0;
}
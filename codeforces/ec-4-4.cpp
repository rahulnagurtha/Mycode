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


inline void Refresh() {
    
}


ll n,k;

VOLL A;
VOLL answer;

bool cmp(PLL lft,PLL ryt) {
	if(lft.FF != ryt.FF) return lft.FF < ryt.FF;
	if(lft.SS*ryt.SS > 0) return lft.FF < ryt.FF;
	return lft.SS > ryt.SS;
}

int main()
{
	// SYNC;
	ll l,r;
	ll startPoint;
	ll cnt = 0;
    slli2(n,k);
    for (ll i = 1; i <= n; ++i) {
    	slli2(l,r);
    	A.pb(mp(l,i));
    	A.pb(mp(r,-1*i));
    }
    sort(A.begin(),A.end(),cmp);
    // cout << A << endl;
    for (int i = 0; i < A.size(); ++i) {
    	if(A[i].SS > 0) {
    		//start point
    		cnt++;
    		if(cnt == k) startPoint = A[i].FF;
    	}
    	else {
    		//close point
    		if(cnt == k) {
    			answer.pb(mp(startPoint,A[i].FF));
    		}
    		cnt--;
    	}
    }
    printf("%d\n",answer.size());
    for (int i = 0; i < answer.size(); ++i) {
    	printf("%I64d %I64d\n",answer[i].FF,answer[i].SS);
    }
    return 0;
}
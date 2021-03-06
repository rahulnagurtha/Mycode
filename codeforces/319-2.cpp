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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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


bool dp[1005][1005];
ll tmp;
VL A;
ll n,m;

int main()
{
	bool exists = false;
	slli2(n,m);
	rep(i,1,n) {
		slli(tmp);
		A.pb(tmp);
	}
	if(n > m) {
		cout << "YES" << endl;
		return 0;
	}
	for (int i = 0; i < A.size(); ++i) {
		dp[i][A[i]%m] = true;
		if(i != 0) {
			for (int j = 0; j < m; ++j) {
				if(dp[i-1][j]) {
					dp[i][j] = true;
					dp[i][(j + A[i]) % m] = true;
				}
			}
		}
	}
	if(dp[A.size()-1][0]) exists = true;
	if(exists) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}
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
#define N                       100007


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

int dp[1005][1005];
string A,B;

int recurse(int l,int r) {
	if(dp[l][r] != -1) return dp[l][r];
	if(l == 0) {
		dp[l][r] = 0;
		for (int i = 1; i <= r; ++i) {
			dp[l][r] += (int)(B[i] - '0');
		}
		return dp[l][r];
	}
	if(r == 0) {
		dp[l][r] = 0;
		for (int i = 1; i <= l; ++i) {
			dp[l][r] += (int)(A[i] - '0');
		}
		return dp[l][r];
	}
	if(A[l] == B[r]) {
		dp[l][r] = recurse(l-1,r-1);
	}
	else {
		dp[l][r] = min((int)(A[l] - '0') + recurse(l-1,r),(int)(B[r] - '0') + recurse(l,r-1)); 
	}
	return dp[l][r];
}

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	A = " ";
    	B = " ";
    	string tmp;
        cin >> tmp;
        A += tmp;
        cin >> tmp;
        B += tmp;
    	fill(dp,-1);
    	cout << recurse(A.size(),B.size()) << endl;
    }
    return 0;
}
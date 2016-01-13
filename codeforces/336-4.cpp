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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dp[505][505];
int c[505],n;


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i < 505; ++i) {
		for (int j = 1; j < 505; ++j) {
			dp[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][i] = 1;
	}
	for (int i = 1; i < n; ++i) {
		if(c[i] == c[i+1]) dp[i][i+1] = 1;
		else dp[i][i+1] = 2;
	}
	for (int i = 3; i <= n; ++i) {
		for (int j = 1; j+i-1 <= n; ++j) {
			dp[j][j+i-1] = min(dp[j][j+i-1],1+dp[j+1][j+i-1]);
			if(c[j] == c[j+i-1]) dp[j][j+i-1] = min(dp[j][j+i-1],dp[j+1][j+i-2]);
			if(c[j] == c[j+1]) dp[j][j+i-1] = min(dp[j][j+i-1],1+dp[j+2][j+i-1]);
			for (int k = j+2; k < j+i-1; ++k) {
				if(c[j] == c[k]) dp[j][j+i-1] = min(dp[j][j+i-1],dp[j+1][k-1]+dp[k+1][j+i-1]);
			}
		}
	}
	cout << dp[1][n] << endl;
    return 0;
}

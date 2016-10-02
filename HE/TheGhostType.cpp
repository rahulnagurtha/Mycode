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


ll dp[1 << 21];

int adjmatrix[21][21];

ll recurse(int cur) {
	if(dp[cur] != -1) return dp[cur];
	if((cur & (cur - 1)) == 0) return 1;
	dp[cur] = 0;
	int cnt[21] = {0};
	VI nums;
	for (int i = 0; i < 20; ++i) {
		if((1 << i & cur)) nums.pb(i + 1);
	}
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = 0; j < nums.size(); ++j) {
			if(adjmatrix[nums[i]][nums[j]] == 1) cnt[nums[j]]++;
		}
	}
	for (int i = 0; i < nums.size(); ++i) {
		if(cnt[nums[i]] == 0) dp[cur] += recurse(cur - (1 << (nums[i]-1)));
	}
	return dp[cur];
}

int main()
{
    fill(dp,-1);
    fill(adjmatrix,0);
    for (int i = 1; i <= 20; ++i) {
    	for (int j = 1; j <= 20; ++j) {
    		if(i != j && ((i&j) == i)) adjmatrix[i][j] = 1;
    	}
    }
    int n;
    cin >> n;
    cout << recurse((1 << n) - 1) << endl;
    return 0;
}
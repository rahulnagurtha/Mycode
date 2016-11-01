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
#define N                     	30017


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






int n,d,tmp;
int gems[N];
int dp[500][N];
map<PII,int> overFlowDp;

int recurse(int cur,int lastLen) {
	if(cur > 30000 || cur < 0) return 0;
	if(lastLen < 500) {
		if(dp[lastLen][cur] != -1) return dp[lastLen][cur];
	}
	else {
		if(overFlowDp.find(mp(lastLen,cur)) != overFlowDp.end()) return overFlowDp[mp(lastLen,cur)];
	}
	int tmp = recurse(cur + lastLen + 1,lastLen + 1);
	if(cur < cur + lastLen - 1 && cur + lastLen - 1 <= 30000) 
		tmp = max(tmp,recurse(cur + lastLen - 1,lastLen - 1));
	if(cur < cur + lastLen && cur + lastLen <= 30000) tmp = max(tmp,recurse(cur + lastLen,lastLen));
	if(lastLen < 500) dp[lastLen][cur] = gems[cur] + tmp;
	else overFlowDp[mp(lastLen,cur)] = gems[cur] + tmp;
	return (gems[cur] + tmp);
}

int main()
{
	fill(dp,-1);
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		gems[tmp]++;
	}
	cout << recurse(d,d) << endl;
    return 0;
}
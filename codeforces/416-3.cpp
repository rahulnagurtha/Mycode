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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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


int n;
int a[5005];
int dp[5005];
int actualCnt[5005];
int xxor[5005][5005];
bool isFeasible[5005][5005];


void preProcess() {
	fill(dp,-1);
	for (int l = 1; l <= n; ++l) {
		int numberOfDifferings = 0;
		int tmpCount[5005];
		bool marked[5005];
		fill(tmpCount,0);
		fill(marked,false);
		for (int r = l; r <= n; ++r) {
			tmpCount[a[r]]++;
			if(!marked[a[r]]) {
				if(tmpCount[a[r]] != actualCnt[a[r]]) {
					numberOfDifferings++;
				}
			}
			else {
				if(tmpCount[a[r]] == actualCnt[a[r]]) {
					numberOfDifferings--;
				}
			}
			marked[a[r]] = true;
			if(numberOfDifferings == 0) isFeasible[l][r] = true;
			// cout << l << " " << r << " -> " << isFeasible[l][r] << endl;
		}
	}
	for (int l = 1; l <= n; ++l) {
		int curVal = 0;
		int tmpCount[5005];
		bool marked[5005];
		fill(tmpCount,0);
		fill(marked,false);
		for (int r = l; r <= n; ++r) {
			if(!marked[a[r]]) {
				curVal = (curVal ^ a[r]);
				marked[a[r]] = true;
			}
			xxor[l][r] = curVal;
		}
	}
	return;
}

int recurse(int pos) {
	if(pos > n) return 0;
	if(dp[pos] != -1) return dp[pos];
	dp[pos] = 0;
	for (int i = pos; i <= n; ++i) {
		if(isFeasible[pos][i]) {
			dp[pos] = max(dp[pos],xxor[pos][i] + recurse(i + 1));
		}
	}
	// cout << pos << "->" << dp[pos] << endl;
	dp[pos] = max(dp[pos],recurse(pos+1));
	return dp[pos];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		actualCnt[a[i]]++;
	}
	preProcess();
	cout << recurse(1) << endl;
    return 0;
}
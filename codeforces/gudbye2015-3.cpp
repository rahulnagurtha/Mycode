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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

vector<string> grid;
int dp[505][505];
int h,w;

void init() {
	fill(dp,0);
	string tmp = "#";
	for (int i = 0; i < 505; ++i) {
		grid.pb(tmp);
	}
	for (int i = 1; i < 505; ++i) {
		tmp += "#";
	}
	grid[0] = tmp;
	return;
}


void preprocess() {
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = dp[i-1][j];
			for (int k = 1; k <= j; ++k) {
				if(grid[i-1][k] == '.' && grid[i][k] == '.') dp[i][j]++;
			}
			for (int k = 1; k < j; ++k) {
				if(grid[i][k] == '.' && grid[i][k+1] == '.') dp[i][j]++;
			}
		}
	}
	return;
}

int main()
{
    init();
    string tmp;
    int q,r1,r2,c1,c2;
    si2(h,w);
    for (int i = 1; i <= h; ++i) {
    	cin >> tmp;
    	grid[i] += tmp;
    }
    preprocess();
    si(q);
    int tempp;
    for (int j = 0; j < q; ++j) {
    	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    	tempp = 0;
    	for (int i = r1; i <= r2; ++i) {
    		if(grid[i][c1-1] == '.' && grid[i][c1] == '.') tempp++;
    	}
    	for (int i = c1; i <= c2; ++i) {
    		if(grid[r1][i] == '.' && grid[r1-1][i] == '.') tempp++;
    	}
    	printf("%d\n",dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] -tempp);
    }
    return 0;
}

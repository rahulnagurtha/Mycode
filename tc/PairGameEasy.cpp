#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define N 						1005

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


class PairGameEasy
{
	int dp[N][N];
	int C,int D;
public:
	void init(int a,int b,int c,int d) {
		C = c;
		D = d;
		fill(dp,-1);
		dp[c][d] = 1;
		return;
	}
	int possible(int a,int b) {
		if(a > C || b > D) return 0;
		if(dp[a][b] != -1) return dp[a][b];
		dp[a][b] = 0;
		return (dp[a][b] = (possible(a+b,b) || possible(a,a+b))); 
	}
	String able(int a, int b, int c, int d) {
		init();
		if(possible(a,b)) return "Able to generate";
		else return "Not able to generate";
	}
};
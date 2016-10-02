#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007
#define BAGS					55
#define WEIGHT					1005

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


int k,m;
int bweight[BAGS];
int bval[BAGS];
int dp[BAGS][WEIGHT];


void solve() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= k ; ++j) {
			if(j >= bweight[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-bweight[i]]+bval[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	printf("Hey stupid robber, you can get %d.\n",dp[m][k]);
}

void cleardata() {
	for (int i = 0; i <= k; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= m; ++i) {
		dp[i][0] = 0;
	}
}

// main code begins now

int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	scanf("%d %d",&k,&m);
    	for (int i = 1; i <= m; ++i) {
    		scanf("%d %d",&bweight[i],&bval[i]);
    	}
    	cleardata();
    	solve();
    }
    return 0;
}
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
#define N 						505

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

int c[N],n,X;
bool dp[N][N][N];



int main()
{
    VI ans;
    int cnt = 0;
    cin >> n >> X;
    for (int i = 1; i <= n; ++i) {
    	cin >> c[i];
    }
    for (int j = 0; j <= X; ++j) {
        for (int k = 0; k <= j; ++k) {
            if(j > 0) dp[1][j][k] = (((k == 0 && c[1] == j) || (c[1] == k && j == k))? true : false);
            else {
                dp[1][j][k] = true;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= X; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j][k] = dp[i-1][j][k];
                if(j-c[i] >= 0) dp[i][j][k] = dp[i-1][j-c[i]][k] || dp[i][j][k];
                if(j-c[i] >= 0 && k-c[i] >= 0) dp[i][j][k] = dp[i-1][j-c[i]][k-c[i]] || dp[i][j][k];
            }
        }
    }
    for (int i = 0; i <= X; ++i) {
    	if(dp[n][X][i]) {
    		cnt++;
    		ans.pb(i);
    	}
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i) {
    	cout << ans[i] << " ";
    }
    printf("\n");
    return 0;
}
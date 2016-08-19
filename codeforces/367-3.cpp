#include <bits/stdc++.h>

using namespace std;

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
#define INF                     100000000000000007LL

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


ll c[100005];
ll dp[2][100005];
string source[100005];
ll n;

int main()
{
    SYNC;
    string cur,nxt;
    cin >> n;
    for (int i = 0; i < 100005; ++i) {
        source[i] = "";
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> source[i];
    }
    dp[0][n] = 0;
    dp[1][n] = c[n];
    for (int i = n - 1; i > 0; --i) {
        dp[0][i] = INF;
        dp[1][i] = INF;
        nxt = source[i+1];
        cur = source[i];
        reverse(nxt.begin(),nxt.end());
        reverse(cur.begin(),cur.end());
        //filling zero
        if(source[i] <= source[i+1]) {
            dp[0][i] = min(dp[0][i],dp[0][i+1]);
        }
        if(source[i] <= nxt) {
            dp[0][i] = min(dp[0][i],dp[1][i+1]);
        }
        //filling one
        if(cur <= source[i+1]) {
            dp[1][i] = min(dp[1][i],c[i] + dp[0][i+1]);
        }
        if(cur <= nxt) {
            dp[1][i] = min(dp[1][i],c[i] + dp[1][i+1]);
        }
    }
    if(dp[0][1] >= INF && dp[1][1] >= INF) printf("-1\n");
    else plli(min(dp[0][1],dp[1][1]));
    return 0;
}
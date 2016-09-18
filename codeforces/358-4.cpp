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


string s,t;
ll n,m,kk;
ll dp[2][11][1005][1005];


int main()
{
    cin >> n >> m >> kk;
    cin >> s ;
    cin >> t;
    for (int l = 0; l < 2; ++l) {
        for (int k = 0; k < 11; ++k) {
            for (int i = 0; i < 1005; ++i) {
                for (int j = 0; j < 1005; ++j) {
                    if(k != 0) dp[l][k][i][j] = INT_MIN;
                    else dp[l][k][i][j] = 0;
                }
            }
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = t.size() - 1; j >= 0; --j) {
            for (int k = 1; k <= kk; ++k) {
                //zero
                if(s[i] == t[j]) {
                    dp[0][k][i][j] = max(1+dp[1][k][i+1][j+1],1+dp[0][k-1][i+1][j+1]);
                    dp[0][k][i][j] = max(dp[0][k][i][j],max(dp[0][k][i+1][j],dp[0][k][i][j+1]));
                }
                else {
                    dp[0][k][i][j] = max(dp[0][k][i+1][j],dp[0][k][i][j+1]);
                }
                //one
                if(s[i] == t[j]) {
                    dp[1][k][i][j] = max(1+dp[1][k][i+1][j+1],1+dp[0][k-1][i+1][j+1]);
                }
                else {
                    dp[1][k][i][j] = INT_MIN;
                }
            }
        }
    }
    cout << max(dp[0][kk][0][0],dp[1][kk][0][0]) << endl;
    return 0;
}
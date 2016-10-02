#include <bits/stdc++.h>

using namespace std;

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



int main()
{
    int n;
    int cost = 0;
    int a[100005],p[100005],dp[100005];
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i] >> p[i];
    }
    dp[0] = p[0];
    for (int i = 1; i < n; ++i)
    {
    	dp[i] = min(dp[i-1],p[i]);
    }
    // for (int i = 0; i < n; ++i)
    // {
    // 	cout << dp[i] << " ";
    // }
    // printf("\n");
    for (int i = 0; i < n; ++i)
    {
    	cost += dp[i]*a[i];
    }
    cout << cost << endl;
    return 0;
}

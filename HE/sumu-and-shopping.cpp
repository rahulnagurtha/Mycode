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


int cost[100002][3],shirt[100002],pant[100002],shoe[100002];


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; ++i) {
    		cin >> shirt[i] >> pant[i] >> shoe[i];
    	}
    	cost[n-1][0] = min(pant[n-1],shoe[n-1]);
    	cost[n-1][1] = min(shirt[n-1],shoe[n-1]);
    	cost[n-1][2] = min(shirt[n-1],pant[n-1]);
    	for (int i = n-2; i >= 0; --i) {
    		cost[i][0] = min(pant[i] + cost[i+1][1],shoe[i] + cost[i+1][2]);
    		cost[i][1] = min(shirt[i] + cost[i+1][0],shoe[i] + cost[i+1][2]);
    		cost[i][2] = min(shirt[i] + cost[i+1][0],pant[i] + cost[i+1][1]);
    	}
    	cout << min(cost[0][0],min(cost[0][1],cost[0][2])) << endl;
    }
    return 0;
}

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
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

bool cmp(PLL one,PLL two) {
	return one.FF < two.FF;
}

int main()
{
    ll n,num[60],balance = 0;
    ll things[5] = {0};
    PLL cost[5];
    bool flag;
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> num[i];
    cin >> cost[0].FF >> cost[1].FF >> cost[2].FF >> cost[3].FF >> cost[4].FF;
    for(ll i = 0; i < 5; ++i) cost[i].SS = i;
    sort(cost,cost+5,cmp);
	for(ll i = 0; i < n; ++i) {
		balance += num[i];
		for(ll j = 4; j >= 0; --j) {
			things[cost[j].SS] += balance/cost[j].FF;
			balance -= (balance/cost[j].FF)*(cost[j].FF);
		}
	}
	cout << things[0] << " " << things[1] << " " << things[2] << " " << things[3] << " " << things[4] << endl; 
    cout << balance << endl;
    return 0;
}
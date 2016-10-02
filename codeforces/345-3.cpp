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

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

int n;
ll ans;
int x,y;
map<int,int> XX;
map<int,int> YY;
map<PII,int> info;

int main()
{
    si(n);
    for (int i = 0; i < n; ++i) {
    	si2(x,y);
    	XX[x]++;
    	YY[y]++;
    	info[mp(x,y)]++;
    }
    for (auto it = XX.begin(); it!=XX.end(); ++it) {
    	ans += ((ll)(it->second)*(it->second - 1))/2;
    }
    for (auto it = YY.begin(); it!=YY.end(); ++it) {
    	ans += ((ll)(it->second)*(it->second - 1))/2;
    }
    for (auto it = info.begin(); it!=info.end(); ++it) {
    	ans -= ((ll)(it->second)*(it->second - 1))/2;
    }
    plli(ans);
    return 0;
}
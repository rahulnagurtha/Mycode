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
#define N 						100005

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

ll a[N];
ll n,m,k;

struct opQuery {
	ll l,r,d;
}operation[N];

ll x,y;

ll queryFreq[N];
ll toAdd[N];

int main()
{
    slli3(n,m,k);
    for (int i = 1; i <= n; ++i) {
    	slli(a[i]);
    }
    for (int i = 1; i <= m; ++i) {
    	slli3(operation[i].l,operation[i].r,operation[i].d);
    }
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
    	slli2(x,y);
    	if(x != 1) {
    		sum--;
    		queryFreq[x-1]--;
    	}
    	queryFreq[y]++;
    	sum++;
    }
    for (int i = 1; i <= m; ++i) {
    	operation[i].d *= sum;
    	sum -= queryFreq[i];
    }
    sum = 0;
    for (int i = 1; i <= m; ++i) {
    	if(operation[i].l != 1) {
    		sum -= operation[i].d;
    		toAdd[operation[i].l - 1] -= operation[i].d;
    	}
    	sum += operation[i].d;
    	toAdd[operation[i].r] += operation[i].d;
    }
    for (int i = 1; i <= n; ++i) {
    	a[i] += sum;
    	sum -= toAdd[i];
    }
    for (int i = 1; i <= n; ++i) {
    	printf("%I64d ",a[i]);
    }
    printf("\n");
    return 0;
}
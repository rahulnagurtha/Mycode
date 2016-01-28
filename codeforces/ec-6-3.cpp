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

int a[300005],b[300005],n;
int status[300005] = {0};
VOII ranges;

int main()
{
    int sz,ans = 0,l,r,cur = 0;
    si(n);
    for (int i = 0; i < n; ++i) {
    	si(a[i]);
    	b[i] = a[i];
    }
    sort(b, b+n);
    sz = unique(b, b + n) - b;
    for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + sz, a[i]) - b;
    if(sz == n) {
    	printf("-1\n");
    	return 0;
    }
    bool found;
    for(int i = 0; i < n;) {
    	l = i + 1;
    	cur++;
    	while((status[a[i]] != cur) && (i < n)) {
    		status[a[i]] = cur;
    		i++;
    	}
    	if(i >= n) ranges[ranges.size()-1].SS = n;
    	else {
    		ans++;
    		ranges.pb(mp(l,i+1));
    		i++;
    	} 
    }
    pi(ans);
    for(int i = 0; i < ranges.size(); ++i) {
    	printf("%d %d\n",ranges[i].FF,ranges[i].SS);
    }
    return 0;
}
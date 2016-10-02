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

int a[500005];
int cnt[1000005] = {0};
int rptr,start,len,dis,n,k;

int main()
{
	len = 0;
	start = 1;
	dis = 1;
	rptr = 0;
	a[0] = 1000002;
    si2(n,k);
    for(int i = 1; i <= n; ++i) si(a[i]);
	cnt[a[0]]++;
	for(int i = 1; i <= n; ++i) {
		cnt[a[i-1]]--;
		if(cnt[a[i-1]] == 0) dis--;
		while(rptr < n && dis <= k) {
			if(cnt[a[rptr+1]] == 0 && dis == k) break;
			rptr++;
			cnt[a[rptr]]++;
			if(cnt[a[rptr]] == 1) dis++;
			if(rptr-i+1 > len) {
				start = i;
				len = rptr-i+1;
			}
		}
	}
	cout << start << " " << start+len-1 << endl;
    return 0;
}
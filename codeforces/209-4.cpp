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
#define INF 					INT_MAX
#define N                     	300007
#define LOGN                    20


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


inline void Refresh() {
    
}

int n;
int st[LOGN][N];
int a[N];
VOII ranges;
bool isThere[N];

void preprocess() {
	for (int i = 1; i <= n; ++i) {
		st[0][i] = a[i];
	}
	int len = 1;
	for (int j = 1; ; ++j) {
		len = (len << 1);
		if(len > n) break;
		for (int i = 1; i <= n; ++i) {
			if(i + (len >> 1) <= n) st[j][i] = __gcd(st[j-1][i],st[j-1][i + (len >> 1)]);
			else st[j][i] = st[j-1][i];
		}
	}
	return;
}

inline int getgcd(int l,int r) {
	int len = log2(r-l+1);
	return __gcd(st[len][l],st[len][r - (1 << len) + 1]);
}


int main()
{
    // SYNC;
    int lft,ryt,ans = 0;
    int total = 0;
    int l,r,mid;
    si(n);
    for (int i = 1; i <= n; ++i) {
    	si(a[i]);
    }
    preprocess();
    for (int i = 1; i <= n; ++i) {
    	//lft
    	l = 1; r = i;
    	while(l != r) {
			mid = (l + r) >> 1;
			if(getgcd(mid,i) == a[i]) r = mid;
			else l = mid + 1;
		}
    	lft = l;
    	//ryt
    	l = i; r = n;
    	while(l != r) {
			mid = (l + r + 1) >> 1;
			if(getgcd(i,mid) == a[i]) l = mid;
			else r = mid - 1;
		}
    	ryt = l;
    	ans = max(ans,ryt - lft);
    	ranges.pb(mp(lft,ryt));
    }
    for (int i = 0; i < n; ++i) {
    	if(ans == (ranges[i].SS - ranges[i].FF) && !isThere[ranges[i].FF]) {
    		isThere[ranges[i].FF] = true;
    		total++;
    	}
    }
    printf("%d %d\n",total,ans);
    for (int i = 1; i <= n; ++i) {
    	if(isThere[i]) printf("%d ",i);
    }
    printf("\n");
    return 0;
}
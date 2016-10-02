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

ll curlen;
ll m,l,c,type,x,n;

VOLL seqSize;
ll val[100005];
map<ll,ll> special;


void query1() {
	slli(x);
	curlen++;
	special[curlen] = x;
	if(curlen < 100005) val[curlen] = x; 
	seqSize.pb(mp(curlen,0));
	return;
}

void query2() {
	slli2(l,c);
	for (int j = 1; j + curlen < 100005 && j <= l*c; ++j) {
		if(j%l == 0) val[j + curlen] = val[l];
		else val[j + curlen] = val[j%l];
	}
	curlen += c*l;
	seqSize.pb(mp(curlen,l));
	return;
}

ll bsearch(ll lft,ll ryt,ll target) {
	assert(lft <= ryt && lft >= 0 && ryt >= 0);
	ll mid = (lft+ryt)/2;
	if(lft == ryt) return lft;
	if(seqSize[mid].FF < target) return bsearch(mid+1,ryt,target);
	else return bsearch(lft,mid,target);
}

int main()
{
	ll idx,at;
	slli(m);
    for (int i = 0; i < m; ++i) {
    	slli(type);
    	if(type == 1) query1();
    	else query2();
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	slli(idx);
    	at = bsearch(0,m - 1,idx);
    	if(seqSize[at].SS == 0) printf("%I64d ",special[idx]);
    	else {
    		ll len = seqSize[at].SS;
    		idx = idx - seqSize[at-1].FF;
    		if(idx%len == 0) printf("%I64d ",val[len]);
    		else printf("%I64d ",val[idx%len]);
    	}
    }
    printf("\n");
    return 0;
}
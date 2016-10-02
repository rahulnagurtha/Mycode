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
#define N                     	200007


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
int cur;
int A[N];
int B[N];
int minimum[4*N];
int maximum[4*N];


void build(int node,int i,int j) {
	if(i>j) return;
	if(i==j) {						
		maximum[node] = A[i];
		minimum[node] = B[i];
		return;
	}
	build(node << 1,i,(i+j) >> 1);
	build((node << 1) + 1,1 + ((i+j) >> 1),j);
	maximum[node] = max(maximum[(node << 1)],maximum[1+(node << 1)]);
	minimum[node] = min(minimum[(node << 1)],minimum[1+(node << 1)]);
	return;
}

PII query(int node,int a,int b,int i,int j) {
	if(a > b || a > j || b < i) return mp(INT_MAX,INT_MIN);
	if(a >= i && b <= j) return mp(minimum[node],maximum[node]);
	PII q1,q2;
	q1 = query((node << 1), a, (a+b) >> 1, i, j);
	q2 = query(1+(node << 1), 1+((a+b) >> 1), b, i, j);
	return mp(min(q1.FF, q2.FF),max(q1.SS, q2.SS));
}

int lowestIdx(int l,int r) {
	if(l > r) return -1;
	int mid = (l+r) >> 1;
	PII tmp = query(1,1,n,cur,mid);
	int mi = tmp.FF,ma = tmp.SS;
	if(l == r) return (mi == ma ? l : -1);
	if(mi == ma) return lowestIdx(l,mid);
	else if(ma > mi) return lowestIdx(l,mid-1);
	else return lowestIdx(mid+1,r);
}

int highestIdx(int l,int r) {
	if(l > r) return -1;
	int mid = (l+r+1) >> 1;
	PII tmp = query(1,1,n,cur,mid);
	int mi = tmp.FF,ma = tmp.SS;
	if(l == r) return l;
	if(mi == ma) return highestIdx(mid,r);
	else if(ma > mi) return highestIdx(l,mid-1);
	else return highestIdx(mid+1,r);
}

int main()
{
	ll ans = 0;
	int l,r;
	si(n);
	for (int i = 1; i <= n; ++i) si(A[i]);
	for (int i = 1; i <= n; ++i) si(B[i]);
	build(1,1,n);
	for (int i = 1; i <= n; ++i) {
		cur = i;
		l = lowestIdx(i,n);
		if(l == -1) continue;
		r = highestIdx(i,n);
		ans += (ll)(r-l+1);
	}
	plli(ans);
    return 0;
}
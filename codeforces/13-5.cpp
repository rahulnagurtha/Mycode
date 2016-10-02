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
#define N                     	100005

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

int power[N];
int nxt[N];
int jumpsNxtBlock[N];
int n,m;
int bsz;


int type,a,b;
int totalBlocks;

inline void updateBlock(int bNum) {
	int lft,ryt;
	lft = (bNum-1)*bsz + 1;
	ryt = min(n,bNum*bsz);
	for (int i = ryt; i >= lft; --i) {	
		if(power[i] + i > ryt) {
			nxt[i] = power[i] + i;
			jumpsNxtBlock[i] = 1;
		}
		else {
			nxt[i] = nxt[power[i] + i];
			jumpsNxtBlock[i] = 1 + jumpsNxtBlock[power[i] + i];
		}
	}
	return;

}

inline void queryCell(int cell) {
	int totalJumps = 0;
	int lastCell;
	while(cell <= n) {
		lastCell = cell;
		totalJumps += jumpsNxtBlock[cell];
		cell = nxt[cell];
	}
	printf("%d %d\n",lastCell,totalJumps);
	return;
}

int main()
{
    si2(n,m);
    bsz = sqrt(n);
    totalBlocks = ceil(n,bsz);
    for (int i = 1; i <= n; ++i) {
    	si(power[i]);
    }
    for (int i = totalBlocks; i > 0; --i) {
    	updateBlock(i);
    }
    for (int i = 0; i < m; ++i) {
    	si(type);
    	if(type == 0) {
    		si2(a,b);
    		power[a] = b;
    		updateBlock(ceil(a,bsz));
    	}
    	else {
    		si(a);
    		queryCell(a);
    	}
    }
    return 0;
}
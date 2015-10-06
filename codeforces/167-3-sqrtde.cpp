#include <bits/stdc++.h>

using namespace std;


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
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

LL a[100005],bsz,tot,n,m,w,h,rb,cur;
PLL blocks[320];                           // (max,lazy)


// main code begins now

int main()
{
    slli(n);
    FOR(i,1,n+1) slli(a[i]);
    bsz = ceil(sqrt(n));
    tot = Ceil(n,bsz);
    for (LL i = 1; i <= tot; ++i) {
    	blocks[i].SS = 0;
    	blocks[i].FF = -1;
    	for (LL j = 1+(i-1)*(bsz); j <= i*bsz && j <= n; ++j) blocks[i].FF = max(blocks[i].FF,a[j]);
    }
    slli(m);
    FOR(i,0,m) {
    	slli2(w,h);
    	rb = Ceil(w,bsz);
    	cur = -1;
    	if(w % bsz != 0) { // not corner
    		if(blocks[rb].SS == 0) { //if not lazy
		    	for (LL j = 1 + (rb-1)*(bsz); j <= w; ++j) cur = max(a[j],cur);
	    	}
	    	else cur = max(cur,blocks[rb].FF);
	    	for (int j = 1; j < rb; ++j) cur = max(cur,blocks[j].FF);
	    	for (int j = 1; j < rb; ++j) {
	    		blocks[j].FF = cur + h;
	    		blocks[j].SS = 1;
	    	}
	    	for (LL j = 1 + bsz*(rb-1); j <= w; ++j) a[j] = cur+h;
	    	blocks[rb].FF = max(blocks[rb].FF,cur+h);
    	}
    	else {
	    	for (int j = 1; j <= rb; ++j) cur = max(cur,blocks[j].FF);
	    	for (int j = 1; j <= rb; ++j) {
	    		blocks[j].FF = cur + h;
	    		blocks[j].SS = 1;
	    	}
    	}
    	printf("%I64d\n",cur);
    }
    return 0;
}
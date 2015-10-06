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
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int n,temp;
LL dp[1 << 20];
bool like[21][21];

unsigned NumberOfSetBits(unsigned i)
{
    const unsigned MASK1  = 0x55555555;
    const unsigned MASK2  = 0x33333333;
    const unsigned MASK4  = 0x0f0f0f0f;
    const unsigned MASK8  = 0x00ff00ff;
    const unsigned MASK16 = 0x0000ffff;

    i = (i&MASK1 ) + (i>>1 &MASK1 );
    i = (i&MASK2 ) + (i>>2 &MASK2 );
    i = (i&MASK4 ) + (i>>4 &MASK4 );
    i = (i&MASK8 ) + (i>>8 &MASK8 );
    i = (i&MASK16) + (i>>16&MASK16);

    return i;
}


void init() {
	fill(dp,-1);
	dp[0] = 1;
	return;
}

LL instance(int mask) {
	LL tmp;
	if(dp[mask] != -1) return dp[mask];
	dp[mask] = 0;
	tmp = (LL)NumberOfSetBits(mask);
	for (int i = 0; i < n; ++i) {
		if(like[tmp][i+1] && (mask&(1 << i)) ) {
			dp[mask] += instance(mask-(1 << i));
		}
	}
	return dp[mask];
}


int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	si(n);
    	init();
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			si(temp);
    			like[i+1][j+1] = temp;
    		}
    	}
    	plli(instance( (1 << n)-1));
    }
    return 0;
}
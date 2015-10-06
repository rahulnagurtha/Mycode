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


int n,m,k;
LL a[20],sat[20][20];
LL dp[(1<<18)-1][20];

void init() {
	fill(dp,-1);
	for (int i = 0; i < 20; ++i) dp[0][i] = 0;
	return;
}



int NumberOfSetBits(int i) {
	i = i - ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

LL getmax(int mask,int last) {
	if(dp[mask][last] != -1) return dp[mask][last];
	for (int i = 0; i < n; ++i) {
		if( mask & (1 << i) ) dp[mask][last] = max(dp[mask][last],a[i+1] + sat[last][i+1] + getmax(mask-(1<<i),i+1));
	}
	return dp[mask][last];
}


int main()
{
	init();
	LL one,two,three,ans = 0;
	int four;
    si3(n,m,k);
    four = 1 << n;
    for (int i = 1; i <= n; ++i) slli(a[i]);
    for (int i = 0; i < k; ++i) {
    	slli3(one,two,three);
    	sat[two][one] = three;
    }
    for (int i = 0; i < four; ++i) {
    	if(NumberOfSetBits(i) == m) {
    		for (int j = 0; j < n; ++j) {
    			if(i&(1 << j)) ans = max(ans,a[j+1] + getmax(i-(1 << j),j+1));
    		}
    	}
    }
    plli(ans);
    return 0;
}
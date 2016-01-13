#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

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
LL dp[(1 << 20) + 5];
bool like[21][21];

int NumberOfSetBits(int i)
{
    int ans = 0;
    while(i > 0) {
        ans += (i%2); 
        i = i/2;
    }
    return ans;
}


void init() {
	fill(dp,-1);
	dp[0] = 1;
	return;
}

LL instance(int mask) {
    assert(mask >= 0);
	LL tmp;
	if(dp[mask] != -1) return dp[mask];
	dp[mask] = 0;
	tmp = (LL)NumberOfSetBits(mask);
	for (int i = 0; i < n; ++i) {
		if(like[tmp][i+1] == true &&  ((mask&(1 << i)) != 0) ) {
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
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= n; ++j) {
    			si(temp);
    			like[i][j] = temp;
    		}
    	}
    	plli(instance( (1 << n)-1));
    }
    return 0;
}
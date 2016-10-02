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

LL n,m,t,final;

LL fastexp(LL b) {										//
	LL ans[4],a[4],c[4];								//
	ans[0] = ans[3] = 1;								//
	a[0] = a[1] = a[2] = 1;
	a[3] = ans[1] = ans[2] = 0;
	while(b > 0) {
		if(b%2 == 1) {
			c[0] = ( (ans[0]*a[0])% MOD + (ans[1]*a[2])% MOD ) % MOD;
			c[1] = ( (ans[0]*a[1])% MOD + (ans[1]*a[3])% MOD ) % MOD;
			c[2] = ( (ans[2]*a[0])% MOD + (ans[3]*a[2])% MOD ) % MOD;
			c[3] = ( (ans[2]*a[1])% MOD + (ans[3]*a[3])% MOD ) % MOD;
			ans[0] = c[0];
			ans[1] = c[1];
			ans[2] = c[2];
			ans[3] = c[3]; 
		}
		c[0] = ( (a[0]*a[0])% MOD + (a[1]*a[2])% MOD ) % MOD;
		c[1] = ( (a[0]*a[1])% MOD + (a[1]*a[3])% MOD ) % MOD;
		c[2] = ( (a[2]*a[0])% MOD + (a[3]*a[2])% MOD ) % MOD;
		c[3] = ( (a[2]*a[1])% MOD + (a[3]*a[3])% MOD ) % MOD;
		a[0] = c[0];
		a[1] = c[1];
		a[2] = c[2];
		a[3] = c[3];
		b /=2;
	}
	return ans[1]%MOD;
}


// main code begins now

int main()
{
    slli(t);
    while(t--) {
    	slli2(n,m);
    	final = fastexp(m+2)-fastexp(n+1);
    	final = rem(final,MOD);
    	plli(final);
    }
    return 0;
}
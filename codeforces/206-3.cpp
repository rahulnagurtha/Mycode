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

LL dp[2][100005][2];
LL n,l,r,ql,qr,w[100005],old,pre,ans;

// main code begins now

int main()
{
	slli3(n,l,r);
	slli2(ql,qr);
    for (int i = 1; i <= n; ++i) slli(w[i]);
    if(n != 1) {
		for (int i = 1; i <= n; ++i) {
			dp[0][i][0] = min(w[i]*l + ql,w[i]*r);
			dp[0][i][1] = min(w[i]*l,w[i]*r + qr);
		}
		pre = 0;
		old = 1;
		for (int j = 2; j < n; ++j){
			swap(pre,old);
			for (int i = 1; i <= n - j + 1; ++i) {
				dp[pre][i][0] = min(w[i]*l + ql + dp[old][i+1][0],w[j+i-1]*r + dp[old][i][1]);
				dp[pre][i][1] = min(w[i]*l + dp[old][i+1][0],w[j+i-1]*r + qr + dp[old][i][1]);
			}
		}
		ans = min(w[1]*l + dp[pre][2][0],w[n]*r + dp[pre][1][1]);
	}
	else ans = min(w[1]*l,w[1]*r);
	plli(ans);
    return 0;
}
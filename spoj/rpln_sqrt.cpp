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
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int a[100005];
int block[321];


int main()
{
    int t;
    int cnt = 0;
    cin >> t ;
    while(t--) {
    	int n,q,lblock,rblock,bsize,bnum,l,r,ans;
    	cnt++;
    	printf("Scenario #%d:\n",cnt);
    	si2(n,q);
    	bsize = ceil(sqrt(n));
    	for (int i = 1; i <= n; ++i) si(a[i]);
    	for (int i = 1; i <= 320; ++i) block[i] = INT_MAX;
    	for (int i = 1; i <= n; ++i) {
    		bnum = Ceil(i,bsize);
    		block[bnum] = min(block[bnum],a[i]);
    	}
    	for (int i = 0; i < q; ++i) {
    		si2(l,r);
    		lblock = Ceil(l,bsize);
    		rblock = Ceil(r,bsize);
    		ans = INT_MAX;
    		if(lblock == rblock) {
    			for (int i = l; i <= r; ++i) {
    				ans = min(ans,a[i]);
    			}
    			printf("%d\n",ans);
    		}
    		else {
    			while(l%bsize != 1) {
    				ans = min(ans,a[l]);
    				l++;
    			}
    			while(r%bsize != 0) {
    				ans = min(ans,a[r]);
    				r--;
    			}
    			lblock = Ceil(l,bsize);
	    		rblock = Ceil(r,bsize);
    			for (int i = lblock; i <= rblock; ++i) ans = min(ans,block[i]);
    			printf("%d\n",ans);
    		}
    	}
    }
    return 0;
}
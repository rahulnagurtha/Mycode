#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
#   define NDEBUG
#endif

#include <bits/stdc++.h>

using namespace std;


#ifdef DEBUG
     #define debug(args...)            {cerr<<__FUNCTION__<<":"<<__LINE__<<":";dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;



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


int n,q,dup[100005],a[100005],bsize,tot;


// main code begins now

int main()
{
	char type;
	int b,c,d,*low,ans,lb,rb,bnum;
	si2(n,q);
	FOR(i,1,n+1) {
		si(a[i]);
		dup[i] = a[i];
	}
	bsize = sqrt(n);
	tot = ceil(n,bsize);
	FOR(i,1,tot + 1) sort(dup+(i-1)*bsize+1,dup+i*bsize+1);
    FOR(i,1,n+1) {
		debug(a[i],dup[i]);
	}
	if(n < 4) {
		for (int i = 0; i < q; ++i) {
			getchar();
	    	scanf("%c",&type);
	    	if(type == 'M') {
	    		si2(b,c);
	    		a[b] = c;
	    	}
	    	else {
	    		ans = 0;
	    		si3(b,c,d);
	    		for (int i = b; i <= c; ++i) {
	    			if(a[i] <= d) ans++;
	    		}
	    		printf("%d\n",ans);
	    	}
    	}
		return 0;
	}
    for (int i = 0; i < q; ++i) {
		getchar();
    	scanf("%c",&type);
    	if(type == 'M') {
    		si2(b,c);
    		bnum = ceil(b,bsize);
    		low = lower_bound(dup + (bnum-1)*(tot) + 1,dup + bnum*tot + 1,a[b]);
    		*low = c;
    		a[b] = c;
    		sort(dup + (bnum-1)*(tot) + 1,dup + bnum*tot + 1);
    	}
    	else {
    		ans = 0;
    		si3(b,c,d);
    		lb = ceil(b,bsize);rb = ceil(c,bsize);
    		if(lb == rb) {
    			for (int i = b; i <= c; ++i) {
    				if(a[i] <= d) ans++;
    			}
    		}
    		else {
    			if(b % bsize != 1) lb++;
    			if(c % bsize != 0) rb--;
    			for (int i = b; i % bsize != 1; ++i,++b) {
    				if(a[i] <= d) ans++;
    			}
    			debug("new",ans);
    			for (int i = c; i % bsize != 0; ++i,--c) {
    				if(a[i] <= d) ans++;
    			}
    			debug("new",ans);
    			if(lb <= rb) {
    				for (int i = lb; i <= rb; ++i) {
    					low = upper_bound(dup + (i-1)*bsize + 1,dup + i*bsize + 1,d);
    					ans += low - (dup + (i-1)*bsize + 1);
    					debug("new",ans);
    				}
    			}
    		}
    		printf("%d\n",ans);
    	}
	  	FOR(i,1,n+1) {
			debug(a[i],dup[i]);
		}
    }
    return 0;
}
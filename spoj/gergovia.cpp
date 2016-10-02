#include <bits/stdc++.h>

using namespace std;



#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b) 			    ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b) 			    (a-(box(a,b))*b)
#define ceil(a,b) 			    ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b) 			    ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


// main code begins now

int main()
{
    LL N,traders[100005],tmp,cur1,cur2,tot1,tot2,work;
    VOII positive,negative;
    // freopen("in.txt", "r", stdin);
    while(1) {
    	cin >> N ;
    	if(N==0) break;
    	positive.clear();
    	negative.clear();
    	work = 0;
    	for (int i = 1; i <= N; ++i) {
    		scanf("%lld",&tmp);
    		if(tmp > 0) positive.pb(mp(i,tmp));
    		else negative.pb(mp(i,-tmp));
    	}
    	tot1 = positive.size();
    	cur1 = 0;
    	tot2 = negative.size();
    	cur2 = 0;
    	while(cur1 < tot1) {
    		if(positive[cur1].SS >= negative[cur2].SS) {
    			positive[cur1].SS -= negative[cur2].SS;
    			work += (abs(positive[cur1].FF-negative[cur2].FF))*negative[cur2].SS;
    			cur2++;
    		}
    		else {
    			negative[cur2].SS -= positive[cur1].SS;
    			work += (abs(positive[cur1].FF-negative[cur2].FF))*positive[cur1].SS;
    			cur1++;
    		}
    	}
    	printf("%lld\n",work);
    }
    return 0;
}

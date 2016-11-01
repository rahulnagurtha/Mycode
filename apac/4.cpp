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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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






inline void Refresh() {
    
}


int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        cout << "Case #" << testcase << ": ";
        int n,m,l;
        int lft[15];
        int ryt[15];
        int price[15];
        int spentSofar = INT_MAX;
        cin >> n >> m >> l;
        for (int i = 0; i < n; ++i) {
        	cin >> lft[i] >> ryt[i] >> price[i];
        }
        for (int i = 1; i < (1 << n); ++i) {
        	int minimum = 0;
        	int maximum = 0;
        	int curPrice = 0;
        	for (int j = 0; j < n; ++j) {
        		if((1 << j) & i) {
        			curPrice += price[j];
        			minimum += lft[j];
        			maximum += ryt[j];
        		}
        	}
        	// cout << i << " " << minimum << " " << maximum << " " << curPrice << endl;
        	if(minimum <= l && l <= maximum && curPrice <= m) {
        		if(curPrice < spentSofar) spentSofar = curPrice;
        	}
        }
        if(spentSofar == INT_MAX) cout << "IMPOSSIBLE" << endl;
        else cout << spentSofar << endl;
        testcase++;
    }
    return 0;
}
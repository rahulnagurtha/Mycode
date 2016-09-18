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
        cout << "Case #" << testcase << ": ";
        int r,c,X;
        int a[15][15] = {0};
        int lft,ryt;
        int ans = 0;
        cin >> r >> c >> X;
        // for (int i = 0; i < r; ++i) {
        // 	for (int j = 0; j < c; ++j) {
        // 		cin >> a[i][j];
        // 	}
        // }
        for (int i = 0; i < X; ++i) {
        	cin >> lft >> ryt;
        	a[lft][ryt] = 1;
        }
        for (int i = 0; i < r; ++i) {
        	for (int j = 0; j < c; ++j) {
        		//lft = i
        		int x1 = i;
        		int x2 = i;
        		int y1 = j;
        		int y2 = j;
        		while(x2 < r && y2 < c) {
	        		int sum = 0;
	        		for (int one = x1; one <= x2; ++one) {
	        			for (int two = y1; two <= y2; ++two) {
	        				sum += a[one][two];
	        			}
	        		}
	        		if(sum == 0) ans++;
	        		x2++;
	        		y2++;

        		}
        	}
        }
        cout << ans << endl;
        testcase++;
    }
    return 0;
}
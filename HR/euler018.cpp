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

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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


int n;
VI num[21];
int dp[21][21];


inline void Refresh() {
    fill(dp,-1);
    for (int i = 0; i < 21; ++i) {
    	num[i].clear();
    }
    return;
}

bool isInside(int x,int y) {
	return ( (0 <= x) && (x < n) && (0 <= y) && (y <= x));
}

int recurse(int x,int y) {
    assert(x < n && y <= x);
	if(x == n - 1) return num[x][y];
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = num[x][y];
	if(isInside(x + 1,y)) dp[x][y] = num[x][y] + recurse(x+1,y);
	if(isInside(x + 1,y+1)) dp[x][y] = max(dp[x][y],num[x][y] + recurse(x+1,y+1));
	return dp[x][y];
}

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
    	int tmp;
    	cin >> n;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < i + 1; ++j) {
    			cin >> tmp;
    			num[i].pb(tmp);
    		}
    	}
    	cout << recurse(0,0) << endl;
    }
    return 0;
}
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


VL costs[306];
ll n,m;
ll dp[306][306];


inline void Refresh() {
    fill(dp,-1);
    for (int i = 0; i < 306; ++i) {
    	costs[i].clear();
    }
    return;
}


void pre_process() {
	for (int i = 1; i <= n; ++i) {
		sort(costs[i].begin(), costs[i].end());
	}
	return;
}


ll solve(ll dayNumber,ll curNumOfPies) {
	if(dayNumber == (n + 1)) return 0;
	if(dp[dayNumber][curNumOfPies] != -1) {
		return dp[dayNumber][curNumOfPies];
	}
	dp[dayNumber][curNumOfPies] = INT_MAX;
	int numOfItemsBought = 0;
	if(curNumOfPies >= dayNumber) {
		dp[dayNumber][curNumOfPies] = solve(dayNumber + 1,curNumOfPies);
	}
	ll sumSoFar = 0;
	for (ll toBuy = 1; toBuy <= m && ((toBuy + curNumOfPies) <= (n)); ++toBuy) {
		sumSoFar += costs[dayNumber][toBuy - 1];
		ll tmp = sumSoFar + (toBuy*toBuy) + solve(dayNumber + 1,curNumOfPies + toBuy);
		if(tmp < dp[dayNumber][curNumOfPies]) numOfItemsBought = toBuy;
		dp[dayNumber][curNumOfPies] = min(tmp,dp[dayNumber][curNumOfPies]);
	}
	// cout << dayNumber << "," << curNumOfPies << " : " << numOfItemsBought << "->" << dp[dayNumber][curNumOfPies] << endl;
	return dp[dayNumber][curNumOfPies];
}



int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
    	ll tmp;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
        	for (int j = 0; j < m; ++j) {
        		cin >> tmp;
        		costs[i].pb(tmp);
        	}
        }
        pre_process();

        //print answer
        cout << "Case #" << testcase << ": ";
        cout << solve(1,0) << endl;
        testcase++;
    }
    return 0;
}
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
#define N                       107


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



ll n,m;
VOLL requests;
ll dp[N][5005];
ll weight[N][N];
ll shortDistance[N][N];



inline void Refresh() {
	requests.clear();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			weight[i][j] = INF;
		}
		weight[i][i] = 0;
	}
	fill(dp,-1);
	return;
}



inline void floyd_warshall()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            shortDistance[i][j] = weight[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                shortDistance[i][j] = min(shortDistance[i][j],shortDistance[i][k] + shortDistance[k][j]);
            }
        }
    }
}



bool is_possible() {
	for (int i = 0; i < requests.size(); ++i) {
		int u = requests[i].FF;
		int v = requests[i].SS;
		if(shortDistance[u][v] == INF) return false;
	}
	if(shortDistance[1][requests[0].FF] == INF) return false;
	for (int i = 1; i < requests.size(); ++i) {
		int u = requests[i - 1].SS;
		int v = requests[i].FF;
		if(shortDistance[u][v] == INF) return false;
	}
	return true;
}




ll solve(ll place,ll reqNum) {
	if(dp[place][reqNum] != -1) return dp[place][reqNum];

	if(reqNum == (requests.size() - 1)) {
		return shortDistance[place][requests.back().SS];
	}

	ll divertValue = 0;
	ll focusedValue = 0;
	PLL curRequest = requests[reqNum];
	PLL nextRequest = requests[reqNum + 1];

	//pick the next request in between
	divertValue =  shortDistance[place][nextRequest.FF]; //go to pickup Point
	divertValue += shortDistance[nextRequest.FF][curRequest.SS];	//now drop the old guy
	divertValue += solve(curRequest.SS,reqNum + 1); //serve the new request

	//do not pick the next request in between
	focusedValue =  shortDistance[place][curRequest.SS]; //go to drop Point
	focusedValue += shortDistance[curRequest.SS][nextRequest.FF];	//now go to the new guy
	focusedValue += solve(nextRequest.FF,reqNum + 1); //serve the new request

	dp[place][reqNum] = min(divertValue,focusedValue);

	return dp[place][reqNum];
}



int main()
{
    int t;
    int testcase = 1;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	ll k,u,v,w,s,d;
    	Refresh();
    	cout << "Case #" << testcase << ": ";
    	testcase++;
        cin >> n >> m >> k;
        for (ll i = 0; i < m; ++i) {
        	cin >> u >> v >> w;
        	weight[u][v] = min(weight[u][v],w);
        	weight[v][u] = min(weight[v][u],w);
        }
        for (ll i = 0; i < k; ++i) {
        	cin >> s >> d;
        	requests.pb(mp(s,d));
        }
        floyd_warshall();
        if(!is_possible()) {
        	cout << "-1" << endl;
        	continue;
        }
        //print answer
        cout << shortDistance[1][requests[0].FF] + solve(requests[0].FF,0) << endl;
    }
    return 0;
}
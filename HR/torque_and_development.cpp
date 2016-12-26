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


ll n,m;
ll cost_lib,cost_road;

VL adjList[N];
ll componentCnt[N];
bool visited[N];


inline void Refresh() {
    for (int i = 0; i < N; ++i) {
    	adjList[i].clear();
    }
    fill(visited,false);
    fill(componentCnt,0);
    return;
}

ll getMeTheBest(ll nodes) {
	return min((nodes-1)*cost_road + cost_lib,nodes*cost_lib);
}

void process() {
	ll ans = 0;
	for (int i = 1; i < N; ++i) {
		if(componentCnt[i] == 0) break;
		ans += getMeTheBest(componentCnt[i]);
	}
	cout << ans << endl;
	return;
}

void dfs(int cur,int comp_Num) {
	visited[cur] = true;
	componentCnt[comp_Num]++;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		int nxt = adjList[cur][i];
		if(!visited[nxt]) dfs(nxt,comp_Num);
	}
	return;
}


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int u,v;
    	Refresh();
    	cin >> n >> m >> cost_lib >> cost_road;
    	for (int i = 0; i < m; ++i) {
    		cin >> u >> v;
    		adjList[u].pb(v);
    		adjList[v].pb(u);
    	}
    	int total_components = 0;
	    for (int i = 1; i <= n; ++i) {
	    	if(!visited[i]) {
	    		total_components++;
	    		dfs(i,total_components);
	    	}
	    }
	    process();
    }
    return 0;
}
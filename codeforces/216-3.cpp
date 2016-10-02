#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64D",&i)
#define slli2(i,j)              scanf("%I64D %I64D",&i,&j)
#define slli3(i,j,k)            scanf("%I64D %I64D %I64D",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64D\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define N 						100005

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
int badRoads[N];
VOII adj[N];
VI res;

void init() {
	fill(badRoads,0);
	return;
}

void dfs2(int cur,int par,int status) {
	bool elect = true;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if(adj[cur][i].FF != par && badRoads[adj[cur][i].FF] != 0) {
			elect = false;
			dfs2(adj[cur][i].FF,cur,adj[cur][i].SS);
		}
	}
	if(elect) res.pb(cur);
	return;
}

void dfs1(int cur,int par,int status) {
	if(status == 2) badRoads[cur]++;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if(adj[cur][i].FF != par) {
			dfs1(adj[cur][i].FF,cur,adj[cur][i].SS);
			badRoads[cur] += badRoads[adj[cur][i].FF];
		}
	}
	return;
}


int main()
{
    int x,y,t;
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	cin >> x >> y >> t;
    	adj[x].pb(mp(y,t));
    	adj[y].pb(mp(x,t));
    }
    init();
    dfs1(1,-1,1);
    if(badRoads[1] != 0) dfs2(1,-1,1);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
    	cout << res[i] << " ";
    }
    printf("\n");
    return 0;
}

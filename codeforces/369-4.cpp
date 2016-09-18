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
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	200007


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

int n;
VI adjList[N];
int cycleVertices,totalVertices;
int posStack[N];
ll power[N];
bool visited[N];


void initialise() {
	fill(posStack,-1);
	power[0] = 1;
	for (int i = 1; i < N; ++i) {
		power[i] = (power[i-1] << 1) % MOD;
	}
	return;
}

void dfs(int cur,int par,int pos) {
	posStack[cur] = pos;
	totalVertices++;
	visited[cur] = true;
	bool excuse = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(!visited[adjList[cur][i]]) {
			dfs(adjList[cur][i],cur,pos+1);
		}
		else {
			if(adjList[cur][i] == par && excuse) excuse = false;
			else {
				cycleVertices = abs(posStack[adjList[cur][i]] - posStack[cur]) + 1;
			}
		}
	}
	return;
}

int main()
{
	SYNC;
	initialise();
	int tmp;
	ll ans = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> tmp;
    	adjList[i].pb(tmp);
    	adjList[tmp].pb(i);
    }
    for (int i = 1; i <= n; ++i) {
    	if(!visited[i]) {
    		totalVertices = 0;
    		cycleVertices = 0;
    		dfs(i,-1,1);
    		ans = rem(ans*power[totalVertices-cycleVertices],MOD);
    		ans = rem(ans*(power[cycleVertices]-2),MOD);
    	}
    }
    cout << ans << endl;
    return 0;
}
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
#define N 						20005

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

VI adjList[N];
bool visited[N];
int one,zero;

void init() {
	for (int i = 0; i < N; ++i) {
		adjList[i].clear();
	}
	fill(visited,true);
	return;
}

void dfs(int cur,int colour) {
	visited[cur] = true;
	if(colour == 0) zero++;
	else one++;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		if(!visited[adjList[cur][i]]) {
			dfs(adjList[cur][i],(colour+1)%2);
		}
	}
	return;
}

int main()
{
    int t;
    int cnt = 0;
    si(t);
    while(t--) {
    	cnt++;
    	init();
    	int n;
    	int ans = 0;
    	int a,b;
    	int maxToSearch = -1;
    	si(n);
    	for (int i = 0; i < n; ++i) {
    		si2(a,b);
    		adjList[a].pb(b);
    		adjList[b].pb(a);
    		visited[a] = false;
    		visited[b] = false;
    		maxToSearch = max(maxToSearch,max(a,b));
    	}
    	for (int i = 1; i <= maxToSearch; ++i) {
    		if(!visited[i]) {
    			one = 0;
    			zero = 0;
    			dfs(i,0);
    			ans += max(one,zero);
    		}
    	}
    	printf("Case %d: ",cnt);
    	pi(ans);
    }
    return 0;
}

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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int n,m;
bool visited[1002];
VOVI graph(1003);


void dfs(int pre) {
	visited[pre] = true;
	for (int i = 0; i < graph[pre].size(); ++i) {
		if(!visited[graph[pre][i]]) dfs(graph[pre][i]);
	}
	return;
}

void init() {
	for (int i = 0; i < 1001; ++i) {
		graph[i].clear();
	}
}

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int temp,ans = 0;
    	si(n);
    	for (int i = 1; i <= n; ++i) {
    		si(m);
    		for (int j = 0; j < m; ++j) {
    			si(temp);
    			graph[temp].pb(i);
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		fill(visited,false);
    		visited[i] = true;
    		dfs(i);
    		ans++;
    		for (int j = 1; j <= n; ++j) {
    			if(!visited[j]) {
    				ans--;
    				break;
    			}
    		}
    	}
    	pi(ans);
    	init();
    }
    return 0;
}

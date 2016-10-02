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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


VOVI graph(10005);
bool visited[10005],cycle,onstack[10005];
int incount[10005];
VI ans;
int n,m;

void dfs(int cur) {
	onstack[cur] = true;
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(!visited[graph[cur][i]]) dfs(graph[cur][i]);
		else if(onstack[graph[cur][i]]) cycle = true;
	}
	onstack[cur] = false;
	return;
}

void topo() {
	priority_queue<int,VI,greater<int> > Q;
	for (int i = 1; i <= n; ++i) {
		if(incount[i] == 0) Q.push(i);
	}
	while(!Q.empty()) {
		cout << Q.top() << " ";
		int tmp = Q.top();
		Q.pop();
		for (int i = 0; i < graph[tmp].size(); ++i) {
			incount[graph[tmp][i]]--;
			if(incount[graph[tmp][i]] == 0) Q.push(graph[tmp][i]);
		}
	}
	printf("\n");
	return;
}

int main()
{
	int out,in;
	fill(visited,false);
	fill(onstack,false);
	cycle = false;
    si2(n,m);
    for (int i = 0; i < m; ++i) {
    	si2(out,in);
    	incount[in]++;
    	graph[out].pb(in);
    }
    for (int i = 1; i <= n; ++i) {
    	if(!visited[i]) dfs(i);
    }
    if (cycle) {
    	printf("Sandro fails.\n");
    }
    else {
    	topo();
    }
    return 0;
}

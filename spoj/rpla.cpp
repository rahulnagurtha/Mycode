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

int n,m;
VOVI graph;
bool visited[1005];
int indegree[1005];


void init() {
	graph.clear();
	VI tmp;
	for (int i = 0; i < 1005; ++i) {
		graph.pb(tmp);
	}
	fill(visited,false);
	fill(indegree,0);
	return;
}


int main()
{
	int t;
	int cnt = 1;
	si(t);
	while(t--) {
		init();
		printf("Scenario #%d:\n",cnt);
		cnt++;
		int rank = 1;
		priority_queue<PII,VOII,greater<PII> > Q;
	    si2(n,m);
	    int in,out,num;
	    for (int i = 0; i < m; ++i) {
	    	si2(in,out);
    		graph[out].pb(in);
    		indegree[in]++;
	    }
	    for (int i = 0; i < n; ++i) {
	    	if(indegree[i] == 0) Q.push(mp(rank,i));
	    }
	    while(!Q.empty()) {
	    	PII tmp = Q.top();
	    	Q.pop();
	    	printf("%d %d\n",tmp.FF,tmp.SS);
	    	for (int i = 0; i < graph[tmp.SS].size(); ++i) {
	    		indegree[graph[tmp.SS][i]]--;
	    		if(indegree[graph[tmp.SS][i]] == 0) Q.push(mp(tmp.FF+1,graph[tmp.SS][i]));
	    	}
	    }
	}
    return 0;
}
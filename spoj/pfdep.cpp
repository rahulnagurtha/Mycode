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
VOVI graph(105);
bool visited[105];
int indegree[105];



int main()
{
	VI ans;
	priority_queue<int,VI,greater<int> > Q;
    si2(n,m);
    int in,out,num;
    for (int i = 0; i < m; ++i) {
    	si2(in,num);
    	for (int j = 0; j < num; ++j) {
    		si(out);
    		graph[out].pb(in);
    		indegree[in]++;
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	if(indegree[i] == 0) Q.push(i);
    }
    while(!Q.empty()) {
    	int tmp = Q.top();
    	Q.pop();
    	ans.pb(tmp);
    	for (int i = 0; i < graph[tmp].size(); ++i) {
    		indegree[graph[tmp][i]]--;
    		if(indegree[graph[tmp][i]] == 0) Q.push(graph[tmp][i]);
    	}
    }
    for (int i = 0; i < ans.size(); ++i) {
    	printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}

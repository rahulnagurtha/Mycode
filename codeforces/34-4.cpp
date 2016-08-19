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
#define N 						50005

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



VI graph[N];
int parent[N];

void dfs(int cur,int pre) {
	parent[cur] = pre;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(graph[cur][i] != pre) dfs(graph[cur][i],cur);
	}
	return;
}


int main()
{
	fill(parent,-1);
    int n,r1,r2,tmp;
    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; ++i) {
    	if(i == r1) continue;
    	cin >> tmp;
    	graph[tmp].pb(i);
    	graph[i].pb(tmp);
    }
    dfs(r2,-1);
    for (int i = 1; i <= n; ++i) {
    	if(parent[i] != -1) printf("%d ",parent[i]);
    }
    printf("\n");
    return 0;
}

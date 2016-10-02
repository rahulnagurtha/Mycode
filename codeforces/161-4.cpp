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

VI adj[N];
deque<int> result;
bool found;
int n,m,k;
int u,v;
int idx[N];

void printresult() {
	found = true;
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";	
	}
	printf("\n");
	return;
}

void dfs(int cur,int pre) {
	result.pb(cur);
	idx[cur] = result.size();
	for (int i = 0; i < adj[cur].size(); ++i) {
		if(adj[cur][i] != pre) {
			if(idx[adj[cur][i]] != -1 && (abs(idx[adj[cur][i]]-idx[cur]) >= k)) {
				printresult();
				return;
			}
			dfs(adj[cur][i],cur);
			if(found) break;
			idx[result.back()] = -1;
		}
	}
	return;
}

int main()
{
	fill(idx,-1);
	found = false;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(1,-1);
    return 0;
}

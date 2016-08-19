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


int n,m;
int tmp;
int num;
int cmpnts;
VI adj[105];
VI language[105];
bool dontKnowAny;
bool visited[105];



void dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < adj[cur].size(); ++i) {
		if(!visited[adj[cur][i]]) dfs(adj[cur][i]);
	}
	return;
}



int main()
{
	dontKnowAny = true;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
    	cin >> num;
    	if(num > 0) dontKnowAny = false;
    	while(num--) {
    		cin >> tmp;
    		language[tmp].pb(i);
    	}
    }
    for (int i = 0; i < 105; ++i) {
    	for (int j = 0; j < language[i].size(); ++j) {
    		for (int k = j + 1; k < language[i].size(); ++k) {
    			adj[language[i][j]].pb(language[i][k]);
    			adj[language[i][k]].pb(language[i][j]);
    		}
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	if(!visited[i]) {
    		cmpnts++;
    		dfs(i);
    	}
    }
    if(dontKnowAny) cout << cmpnts << endl;
    else cout << cmpnts - 1 << endl;
    return 0;
}
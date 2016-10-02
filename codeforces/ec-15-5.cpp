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
#define N                     	100007
#define LOGN 					35

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

ll n,k;
ll nxt[N];
ll weight[N];
ll to[LOGN][N];
bool visited[N];
ll minWeight[LOGN][N];
ll sumWeight[LOGN][N];


void dfs(ll cur) {
	if(visited[cur]) return;
	visited[cur] = true;
	minWeight[0][cur] = weight[cur];
	sumWeight[0][cur] = weight[cur];
	to[0][cur] = nxt[cur];
	dfs(nxt[cur]);
	return;
}


int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	cin >> nxt[i];
    }
    for (int i = 0; i < n; ++i) {
    	cin >> weight[i];
    }
    for (int i = 0; i < n; ++i) {
    	if(!visited[i]) dfs(i);
    }
    for (ll i = 1; i < LOGN; ++i) {
    	for (ll j = 0; j < n; ++j) {
    		to[i][j] = to[i-1][to[i-1][j]];
    		minWeight[i][j] = min(minWeight[i-1][j],minWeight[i-1][to[i-1][j]]);
    		sumWeight[i][j] = sumWeight[i-1][j] + sumWeight[i-1][to[i-1][j]];
    	}
    }
    for (ll i = 0; i < n; ++i) {
    	ll tmp = 1;
    	ll cur = i;
    	ll cnt = 0;
    	ll s = 0;
    	ll m = INF;
    	while(tmp <= k) {
    		if(tmp & k) {
    			s += sumWeight[cnt][cur];
    			m = min(m,minWeight[cnt][cur]);
    			cur = to[cnt][cur];
    		}
    		cnt++;
    		tmp = tmp << 1;
    	}
    	cout << s << " " << m << endl;
    }
    return 0;
}
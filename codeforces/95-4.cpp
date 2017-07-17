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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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



int n,x,y;
int T[3006];
VI adjList[3006];
bool visited[3006];
int dist[3006];
int position[3006];
bool isInStack[3006];
bool isPartOfCycle[3006];


void go(int cur,int par,int pos);
void dfs(int cur,int par,int pos);

void process(int l,int r) {
	for (int i = l; i <= r; ++i) {
		dist[T[i]] = 0;
		isPartOfCycle[T[i]] =true;
	}
	return;
}

void go(int cur,int par,int pos) {
	T[pos] = cur;
	position[cur] = pos;
	isInStack[cur] = true;
	dfs(cur,par,pos);
	isInStack[cur] = false;
}


void dfs(int cur,int par,int pos) {
	visited[cur] = true;
	for (int i = 0; i < adjList[cur].size(); ++i) {
		int nxt = adjList[cur][i];
		if(nxt != par) {
			if(isInStack[nxt]) process(min(position[nxt],position[cur]),max(position[nxt],position[cur]));
			else if(!visited[nxt]) go(nxt,cur,pos + 1);
		}
	}
	return;
}

int main()
{
	deque<int> Q;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		adjList[x].pb(y);
		adjList[y].pb(x);
	}
	// cout << adjList[1] << endl;
	go(1,-1,1);
	fill(visited,false);
	for (int i = 1; i <= n; ++i) {
		if(isPartOfCycle[i]) {
			Q.pb(i);
			visited[i] = true;
		}
	}
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop_front();
		for (int i = 0; i < adjList[cur].size(); ++i) {
			int nxt = adjList[cur][i];
			if(!visited[nxt]) {
				visited[nxt] = true;
				Q.pb(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << dist[i] << " ";
	}
	cout << endl;
    return 0;
}
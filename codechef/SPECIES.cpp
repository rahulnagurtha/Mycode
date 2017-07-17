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

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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



vector<string> adjList;
int n;
ll ans;
bool isValid;



bool isInside(int x,int y) {
	return ((0 <= x) && (x < n) && (0 <= y) && (y < n));
}


void Refresh() {
	ans = 1;
	adjList.clear();
	isValid = true;
	return;
}

void dfs_pass_one(int x,int y) {
	char src = adjList[x][y];
	for (int i = 0; i < 4; ++i) {
		if(!isValid) return;
		int xx = x + dX[i];
		int yy = y + dY[i];
		if(!isInside(xx,yy)) continue;
		if(src == 'G') {
			if(adjList[xx][yy] != '.') isValid = false;
		}
		else if(src == 'B') {
			if(adjList[xx][yy] == '?') {
				adjList[xx][yy] = 'B';
				dfs_pass_one(xx,yy);
			}
			else if((adjList[xx][yy] == '.') || (adjList[xx][yy] == 'B')) {
				continue;
			}
			else isValid = false;
		}
		else {
			if(adjList[xx][yy] == '?') {
				adjList[xx][yy] = 'P';
				dfs_pass_one(xx,yy);
			}
			else if((adjList[xx][yy] == '.') || (adjList[xx][yy] == 'P')) {
				continue;
			}
			else isValid = false;
		}
	}
	return;
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(!isValid) return;
			if((adjList[i][j] == 'B') || (adjList[i][j] == 'G') || (adjList[i][j] == 'P')) 
				dfs_pass_one(i,j);
		}
	}
	return;
}

int dfs_pass_two(int x,int y) {
	int ret = 1;
	adjList[x][y] = '.';
	for (int i = 0; i < 4; ++i) {
		int xx = x + dX[i];
		int yy = y + dY[i];
		if(!isInside(xx,yy)) continue;
		if(adjList[xx][yy] == '?') ret += dfs_pass_two(xx,yy);
	}
	return ret;
}


void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(adjList[i][j] == '?') {
				int cur = dfs_pass_two(i,j);
				if(cur == 1) ans = (ans*3) % MOD;
				else ans = (ans*2) % MOD;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
		string tmp;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			adjList.pb(tmp);
		}
		preprocess();
		if(!isValid) printf("0\n");
		else solve();
    }
    return 0;
}

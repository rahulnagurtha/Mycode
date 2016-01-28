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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int n,m,region[1005][1005] = {0},cnt[1000005] = {0};
bool visited[1005][1005] = {false};
char grid[1005][1005];


void input() {
	fill(grid,'*');
	si2(n,m);
	getchar();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%c",&grid[i][j]);
		}
		getchar();
	}
	return;
}

void dfs(int x,int y,int reg) {
	visited[x][y] = true;
	region[x][y] = reg;
	if(!visited[x+1][y] && grid[x+1][y] != '*') dfs(x+1,y,reg);
	if(!visited[x-1][y] && grid[x-1][y] != '*') dfs(x-1,y,reg);
	if(!visited[x][y+1] && grid[x][y+1] != '*') dfs(x,y+1,reg);
	if(!visited[x][y-1] && grid[x][y-1] != '*') dfs(x,y-1,reg);
	return;
}


void process() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(grid[i][j] != '*'){
				cnt[region[i][j]]++;
			}
		}
	}
	return;
}


void walkover() {
	int pre = 1;
	for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if(!visited[i][j] && grid[i][j] != '*') {
    			dfs(i,j,pre);
    			pre++;
    		}
    	}
    }
    return;
}

inline void combine(bool u,bool d,bool l,bool r,int i,int j) {
	VI dis;
	dis.pb(0);
	int cur = 1;
	if(u && find(dis.begin(),dis.end(),region[i-1][j]) == dis.end()) {
		cur += cnt[region[i-1][j]];
		dis.pb(region[i-1][j]);
	}
	if(d && find(dis.begin(),dis.end(),region[i+1][j]) == dis.end()) {
		cur += cnt[region[i+1][j]];
		dis.pb(region[i+1][j]);
	}
	if(l && find(dis.begin(),dis.end(),region[i][j-1]) == dis.end()) {
		cur += cnt[region[i][j-1]];
		dis.pb(region[i][j-1]);
	}
	if(r && find(dis.begin(),dis.end(),region[i][j+1]) == dis.end()) {
		cur += cnt[region[i][j+1]];
		dis.pb(region[i][j+1]);
	}
	printf("%d",cur%10);
	return;
}


void solve() {
	int temp;
	bool u,l,r,d;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(grid[i][j] != '.') {
				l = r = u = d = false;
				if(grid[i-1][j] != '*') u = true;
				if(grid[i+1][j] != '*') d = true;
				if(grid[i][j-1] != '*') l = true;
				if(grid[i][j+1] != '*') r = true;
				combine(u,d,l,r,i,j);
			}
			else printf(".");
		}
		printf("\n");
	}
}


int main()
{
	input();
    walkover();
    process();
    solve();
    return 0;
}
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
#define N                     	1007


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
string grid[N];
bool visited[N][N];

inline bool isInside(int x,int y) {
	return (1 <= x && x <= n && 0 <= y && y <= m);
}

void dfs(int x,int y) {
	visited[x][y] = true;
	if(grid[x][y] == 'N' && !visited[x + dX[0]][y+dY[0]]) dfs(x + dX[0],y + dY[0]);
	else if(grid[x][y] == 'E' && !visited[x + dX[1]][y+dY[1]]) dfs(x + dX[1],y + dY[1]);
	else if(grid[x][y] == 'S' && !visited[x + dX[2]][y+dY[2]]) dfs(x + dX[2],y + dY[2]);
	else if(grid[x][y] == 'W' && !visited[x + dX[3]][y+dY[3]]) dfs(x + dX[3],y + dY[3]);
	for (int i = 0; i < 4; ++i) {
		if(isInside(x + dX[i],y+dY[i])) {
			if(i == 0 && grid[x + dX[0]][y+dY[0]] == 'S' && !visited[x + dX[0]][y+dY[0]]) dfs(x + dX[0],y + dY[0]);
			if(i == 1 && grid[x + dX[1]][y+dY[1]] == 'W' && !visited[x + dX[1]][y+dY[1]]) dfs(x + dX[1],y + dY[1]);
			if(i == 2 && grid[x + dX[2]][y+dY[2]] == 'N' && !visited[x + dX[2]][y+dY[2]]) dfs(x + dX[2],y + dY[2]);
			if(i == 3 && grid[x + dX[3]][y+dY[3]] == 'E' && !visited[x + dX[3]][y+dY[3]]) dfs(x + dX[3],y + dY[3]);
		}
	}
	return;
}

int main()
{
    si2(n,m);
    m--;
    int cmp = 0;
    for (int i = 1; i <= n; ++i) {
    	cin >> grid[i];
    }
	fill(visited,false);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < grid[i].size(); ++j) {
    		if(!visited[i][j]) {
    			cmp++;
    			dfs(i,j);
    		}
    	}
    }
    printf("%d\n",cmp);
    return 0;
}

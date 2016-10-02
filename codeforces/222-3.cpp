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

int n,m,k,cnt;
string grid[505];
bool visited[505][505];

bool isOut(int x,int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

void dfs(int x,int y) {
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		if(!isOut(x+dX[i],y+dY[i]) && !visited[x+dX[i]][y+dY[i]] && cnt < k && grid[x+dX[i]][y+dY[i]] != '#') {
			dfs(x+dX[i],y+dY[i]);
		}
	}
	return;
}

int main()
{
	cnt = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
    	cin >> grid[i];
    }
    fill(visited,false);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if(grid[i][j] == '.') {
    			cnt++;
    		}
    	}
    }
    k = cnt-k;
    cnt = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if(grid[i][j] == '.') {
    			if(cnt < k) dfs(i,j);
    			break;
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if(grid[i][j] == '.' && !visited[i][j]) {
    			grid[i][j] = 'X';
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	cout << grid[i] << endl;
    }
    return 0;
}
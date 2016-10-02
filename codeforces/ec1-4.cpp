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
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int a[1000005];
int n,m,k,x,y;
vector<string> grid;
int pic[1002][1002];
int com[1002][1002];
bool visited[1002][1002];



void piccount() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '*') continue;
			if(i-1 >= 0 && grid[i-1][j] == '*') pic[i][j]++;
			if(i+1 < n && grid[i+1][j] == '*') pic[i][j]++;
			if(j-1 >= 0 && grid[i][j-1] == '*') pic[i][j]++;
			if(j+1 < m && grid[i][j+1] == '*') pic[i][j]++;
		}

	}
	return;
}



void dfs(int x,int y,int compo) {
	visited[x][y] = true;
	com[x][y] = compo;
	if(x-1 >= 0 && grid[x-1][y] == '.' && !visited[x-1][y]) dfs(x-1,y,compo);
	if(x+1 < n && grid[x+1][y] == '.' && !visited[x+1][y]) dfs(x+1,y,compo);
	if(y-1 >= 0 && grid[x][y-1] == '.' && !visited[x][y-1]) dfs(x,y-1,compo);
	if(y+1 < m && grid[x][y+1] == '.' && !visited[x][y+1]) dfs(x,y+1,compo);
	return;
}



int main()
{
	string tmp;
	int cnt = 1;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		grid.pb(tmp);
	}
	piccount();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(!visited[i][j] && grid[i][j] == '.') {
				dfs(i,j,cnt);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[com[i][j]] += pic[i][j];
		}
	}
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		cout << a[com[x-1][y-1]] << endl;
	}
    return 0;
}

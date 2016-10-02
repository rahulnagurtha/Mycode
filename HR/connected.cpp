#include <bits/stdc++.h>

using namespace std;

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

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

int m,n,tmp,reg,cnt[1000];
char grid[15][15];
bool visited[15][15];

void init() {
	reg = 1;
	fill(cnt,0);
	fill(grid,'0');
	return;
}

void dfs(int pre,int x,int y) {
	if(grid[x][y] == '0') return;
	visited[x][y] = true;
	cnt[pre]++;
	if( (x-1 > 0 && x-1 <= m) && (y-1 > 0 && y-1 <= n) && (!visited[x-1][y-1])) dfs(pre,x-1,y-1);
	if( (x-1 > 0 && x-1 <= m) && (y > 0 && y <= n) && (!visited[x-1][y])) dfs(pre,x-1,y); 
	if( (x-1 > 0 && x-1 <= m) && (y+1 > 0 && y+1 <= n) && (!visited[x-1][y+1])) dfs(pre,x-1,y+1);
	if( (x > 0 && x <= m) && (y-1 > 0 && y-1 <= n) && (!visited[x][y-1])) dfs(pre,x,y-1);
	if( (x > 0 && x <= m) && (y+1 > 0 && y+1 <= n) && (!visited[x][y+1])) dfs(pre,x,y+1);
	if( (x+1 > 0 && x+1 <= m) && (y-1 > 0 && y-1 <= n) && (!visited[x+1][y-1])) dfs(pre,x+1,y-1);
	if( (x+1 > 0 && x+1 <= m) && (y > 0 && y <= n) && (!visited[x+1][y])) dfs(pre,x+1,y);
	if( (x+1 > 0 && x+1 <= m) && (y+1 > 0 && y+1 <= n) && (!visited[x+1][y+1])) dfs(pre,x+1,y+1);
	return;
}

void walkanddeclare() {
	int ans = 0;
	for(int i = 1; i < 105; ++i) {
		ans = max(cnt[i],ans);
	}
	printf("%d\n",ans);
	return;
}


int main()
{
	init();
	cin >> m >> n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> tmp;
			if(tmp == 1) grid[i][j] = '1';
			else grid[i][j] = '0';
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			if((!visited[i][j]) && grid[i][j] != '0') {
				dfs(reg,i,j);
				reg++;
			}
		}
	}
	walkanddeclare();
    return 0;
}

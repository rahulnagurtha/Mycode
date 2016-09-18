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

bool visited[105][105];
string grid[105];
int n,m;
string target;
bool possible;

inline bool isInside(int x,int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

void initialise() {
	possible = false;
	for (int i = 0; i < 105; ++i) {
		grid[i] = "";
	}
	fill(visited,false);
	return;
}

bool dfs(int x,int y,int pos) {
	if(pos == 9) return (grid[x][y] == target[pos]);
	if(grid[x][y] != target[pos]) return false;
	bool canExtend = false;
	visited[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		if(isInside(x + dX[i],y + dY[i]) && !visited[x + dX[i]][y + dY[i]]) {
			canExtend = dfs(x + dX[i],y + dY[i],pos + 1);
		}
		if(canExtend) break;
	}
	visited[x][y] = false;
	return canExtend;
}


int main()
{
	target = "ALLIZZWELL";
    int t;
    cin >> t ;
    while(t--) {
    	initialise();
    	cin >> n >> m;
    	for (int i = 0; i < n; ++i) {
    		cin >> grid[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			if(!possible) {
    				possible = dfs(i,j,0);
    			}
    			else break;
    		}
    	}
    	if(possible) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
    return 0;
}
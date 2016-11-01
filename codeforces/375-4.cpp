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


ll n,m,k;
ll label[55][55];
string grid[55];
bool visited[55][55];


bool isInside(ll x,ll y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}


void dfs_pass_one(ll x,ll y,ll curLabel) {
	visited[x][y] = true;
	label[x][y] = curLabel;
	for (int i = 0; i < 4; ++i) {
		ll xx = x + dX[i];
		ll yy = y + dY[i];
		if(isInside(xx,yy) && !visited[xx][yy] && grid[xx][yy] != '*') {
			dfs_pass_one(xx,yy,curLabel);
		}
	}
	return;
}



int main()
{
	ll ans = 0;
	string tmp;
	cin >> n >> m >> k;
	for (ll i = 1; i <= n; ++i) {
		cin >> tmp;
		grid[i] = " ";
		grid[i] += tmp;
	}

	//left line
	for (ll i = 1; i <= n; ++i) {
		if(!visited[i][1] && grid[i][1] != '*') dfs_pass_one(i,1,-1);
	}
	//right line
	for (ll i = 1; i <= n; ++i) {
		if(!visited[i][m] && grid[i][m] != '*') dfs_pass_one(i,m,-1);
	}
	//top line
	for (ll i = 1; i <= m; ++i) {
		if(!visited[1][i] && grid[1][i] != '*') dfs_pass_one(1,i,-1);
	}
	//top line
	for (ll i = 1; i <= m; ++i) {
		if(!visited[n][i] && grid[n][i] != '*') dfs_pass_one(n,i,-1);
	}

	ll components = 0;

	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= m; ++j) {
			if(!visited[i][j] && grid[i][j] == '.') {
				components++;
				dfs_pass_one(i,j,components);
			}
		}
	}
	VOLL data;
	VL toConvert;
	for (ll i = 1; i <= components; ++i) {
		ll cnt = 0;
		for (ll l = 1; l <= n; ++l) {
			for (ll r = 1; r <= m; ++r) {
				if(label[l][r] == i) cnt++;
			}
		}
		data.pb(mp(cnt,i));
	}
	sort(data.begin(),data.end());
	for (ll i = 0; i < components - k; ++i) {
		toConvert.pb(data[i].SS);
	}
	for (int i = 0; i < toConvert.size(); ++i) {
		for (ll l = 1; l <= n; ++l) {
			for (ll r = 1; r <= m; ++r) {
				if (label[l][r] == toConvert[i]) {
					grid[l][r] = '*';
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= m; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
    return 0;
}
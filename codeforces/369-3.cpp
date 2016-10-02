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
#define INF 					1000000000000007LL
#define N                     	107


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


ll n,m,x;
ll p[N][N];
ll color[N];
ll a[N][N][N];


int main()
{
    SYNC;
    cin >> n >> m >> x;
    color[0] = -1;
    for (ll i = 1; i <= n; ++i) {
    	cin >> color[i];
    }
    for (ll i = 1; i <= n; ++i) {
    	for (ll j = 1; j <= m; ++j) {
    		cin >> p[i][j];
    	}
    }
    if(n == 1) {
    	if(color[1] == 0 && x == 1) {
    		ll ans = INF;
    		for (ll i = 1; i <= m; ++i) {
    			ans = min(ans,p[1][i]);
    		}
    		cout << ans << endl;
    		return 0;
    	}
    	if(color[1] == 0 && x != 1) {
    		printf("-1\n");
    		return 0;
    	}
    	if(color[1] != 0 && x == 1) {
    		printf("0\n");
    		return 0;
    	}
    	if(color[1] != 0 && x != 1) {
    		printf("-1\n");
    		return 0;
    	}
    }
    for (ll i = 0; i < N; ++i) {
    	for (ll j = 0; j < N; ++j) {
    		for (ll k = 0; k < N; ++k) {
    			a[i][j][k] = INF;
    		}
    	}
    }
    //i = n
    for (ll j = 1; j <= m; ++j) {
		for (ll k = 0; k <= 1; ++k) {
			if(color[n] == 0) {
				for (ll curColor = 1; curColor <= m; ++curColor) {
					if(j != curColor && k == 1) a[n][j][k] = min(a[n][j][k],p[n][curColor]);
					if(j == curColor && k == 0) a[n][j][k] = min(a[n][j][k],p[n][curColor]);
				}
			}
			else {
				if(color[n] == j && k == 0) a[n][j][k] = 0;
				if(color[n] != j && k == 1) a[n][j][k] = 0;
			}
		}
    }
    for (ll i = n-1; i > 1;--i) {
    	for (ll j = 1; j <= m; ++j) {
    		for (ll k = 0; k <= x; ++k) {
    			if(color[i] == 0) {
					for (ll curColor = 1; curColor <= m; ++curColor) {
						if(j != curColor && k > 0) a[i][j][k] = min(a[i][j][k],p[i][curColor] + a[i+1][curColor][k-1]);
						if(j == curColor) a[i][j][k] = min(a[i][j][k],p[i][curColor] + a[i+1][curColor][k]);
					}
				}
				else {
					if(color[i] == j) a[i][j][k] = min(a[i][j][k],a[i+1][j][k]);
					if(color[i] != j && k > 0) a[i][j][k] = min(a[i][j][k],a[i+1][color[i]][k-1]);
				}
    		}
    	}
    }
    //processing 1
    ll ans = INF;
    if(color[1] == 0) {
    	for (ll curColor = 1; curColor <= m; ++curColor) {
    		if(x > 0) ans = min(ans,p[1][curColor] + a[2][curColor][x-1]);
    	}
    	if(ans >= INF) printf("-1\n");
    	else cout << ans << endl;
    	return 0;
    }
    else {
		if(x > 0) ans = min(ans,a[2][color[1]][x-1]);
    	if(ans >= INF) printf("-1\n");
    	else cout << ans << endl;
    	return 0;
    }
    return 0;
}
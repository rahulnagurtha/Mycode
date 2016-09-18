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

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define INF                     1000000007LL

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



bool marked[30][30];
ll dis[30][30];
string grid[30];
int n,m;

bool isInside(int x,int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

void initialise() {
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < 30; ++j) {
			dis[i][j] = INF;
		}
		grid[i] = "";
	}
	fill(marked,false);
	return;
}


int main()
{
    while(1) {
    	initialise();
    	ll ans = 0,d;
    	int xx,yy;
    	string name;
    	ll weight,vertex;
    	priority_queue<pair<ll,PII>,vector<pair<ll,PII> >,greater<pair<ll,PII> > > Q;
    	si2(m,n);
    	if(m == 0 && n == 0) break;
    	for (int i = 0; i < n; ++i) {
    		cin >> grid[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			if(grid[i][j] == 'S') {
    				xx = i;
    				yy = j;
    				break;
    			}
    		}
    	}
    	dis[xx][yy] = 0;
    	Q.push(mp(0,mp(xx,yy)));
    	while(!Q.empty()) {
    		xx = Q.top().SS.FF;
    		yy = Q.top().SS.SS;
    		if(grid[xx][yy] == 'D') {
    			ans = dis[xx][yy];
    			break;
    		}
    		weight = Q.top().FF;
    		Q.pop();
    		if(marked[xx][yy]) continue;
    		marked[xx][yy] = true;
    		for (int i = 0; i < 4; ++i) {
    			if(isInside(xx + dX[i],yy + dY[i]) && !marked[xx + dX[i]][yy + dY[i]]){
    				if(grid[xx + dX[i]][yy + dY[i]] == 'X') d = INF;
    				else if(grid[xx + dX[i]][yy + dY[i]] == 'S') d = 0;
    				else if(grid[xx + dX[i]][yy + dY[i]] == 'D') d = 0;
    				else d = (ll)(grid[xx + dX[i]][yy + dY[i]] - '0');
    				if(dis[xx + dX[i]][yy + dY[i]] > d + dis[xx][yy]) {
    					dis[xx + dX[i]][yy + dY[i]] = d + dis[xx][yy];
    					Q.push(mp(d + dis[xx][yy],mp(xx + dX[i],yy + dY[i])));
    				}
    			}
    		}
    	}
    	cout << ans << endl;
    }
    return 0;
}
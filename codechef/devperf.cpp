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


int rU[1003],rD[1003],cL[1003],cR[1003],m,n;
bool row[1003],col[1003],a,b;
vector<string> grid;


void process() {
	a = false,b = false;
	for (int i = 0; i < 1003; ++i) {
		row[i] = col[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(grid[i][j] == '*') {
				row[i] = true;
				a = true;
				break;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if(grid[j][i] == '*') {
				col[i] = true;
				b = true;
				break;
			}
		}
	}
	rU[0] = rD[n-1] = 0;
	for (int i = 1; i < n; ++i) {
		if(rU[i-1] != 0) rU[i] = rU[i-1] + 1;
		else if(row[i-1]) rU[i] = 1;
		else rU[i] = 0;
	}
	for (int i = n-2; i >= 0; --i) {
		if(rD[i+1] != 0) rD[i] = rD[i+1] + 1;
		else if(row[i+1]) rD[i] = 1;
		else rD[i] = 0;
	}
	cL[0] = cR[m-1] = 0;
	for (int i = 1; i < m; ++i) {
		if(cL[i-1] != 0) cL[i] = cL[i-1] + 1;
		else if(col[i-1]) cL[i] = 1;
		else cL[i] = 0;
	}
	for (int i = m-2; i >= 0; --i) {
		if(cR[i+1] != 0) cR[i] = cR[i+1] + 1;
		else if(col[i+1]) cR[i] = 1;
		else cR[i] = 0;
	}
	return;
}


void calculate() {
	if( !a && !b ) {
		cout << "0" << endl;
		return;
	}
	int ans = 1000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans = min(ans,1 + max(max(cL[j],cR[j]),max(rU[i],rD[i])));
		}
	}
	cout << ans << endl;
	return;
}


int main()
{
	SYNC;
    int t;
    cin >> t ;
    while(t--) {
    	grid.clear();
    	string tmp;
    	cin >> n >> m;
    	for (int i = 0; i < n; ++i) {
    		cin >> tmp;
    		grid.pb(tmp);
    	}
    	process();
    	calculate();
    }
    return 0;
}

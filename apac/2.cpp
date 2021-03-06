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
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


typedef long long int ll;
typedef long double ld;
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





ld polls[4100][4100];

inline void Refresh() {
    for(int i = 0; i < 4010; i++) {
		for(int j = 0 ; j < 4010; j++)
			polls[i][j] = 0;
	}
	return;
}



int main()
{
	ll n,m,t;
	freopen("in.txt", "r", stdin);
	cin >> t;
	int testcase = 1;
	while(t--) {
		Refresh();
		printf("Case #%d: ",testcase);
		testcase++;
		cin >> n >> m;
		
		if(m == 0) {
			printf("1.0000000000\n");
			continue;
		}
		polls[1][1] = n;
		polls[1][1] /= (ld)(m+n);
		for(int i = 1;i < m + n; i++) {
			for(int j = 1;j <= n; j++) {
				if(j > i) continue;
				ll A = i+j;
				ll B = i-j;
				if(A % 2 == 1 || B%2 == 1 || B < 0) continue;
				A /= 2;
				B /= 2;
				ll x1 = n-A;
				ll x2 = m-B;
				if(x1 > n || x1 < 0 || x2 > m || x2 < 0) continue;
				ll sum3 = x1+x2;
				polls[i+1][j+1] += polls[i][j]*(x1)/(ld)sum3;
				polls[i+1][j-1] += polls[i][j]*(x2)/(ld)sum3;
			}
		}
		printf("%.9Lf\n",polls[m+n][n-m]);
	}

	return 0;
}
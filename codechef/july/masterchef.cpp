#include <bits/stdc++.h>

using namespace std;


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
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007


typedef long long int ll;

ll dp[100005][501];
int newarr[100005],value[100005];

ll knapsack(int n,int k) {
	for (int i = 0; i <= k; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if(j-value[i] >= 0) dp[i][j] = max(dp[i-1][j],newarr[i]+dp[i-1][j-value[i]]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][k];
}

// main code begins now

int main()
{
	int bsize,tot,n,k,m,t,l,r,c,nsize,lb,rb;
	int arr[100005],cost[100005],mi[320],ma[320],lazy[320];
	ll ans,tmp;
	cin >> t;
	while(t--) {
		nsize = 0;
		ans = 0;
		cin >> n >> k >> m;
		bsize = ceil(sqrt(n));
		tot = Ceil(n,bsize);
		FOR(i,1,n+1) cin >> arr[i];
		FOR(i,1,n+1) cost[i] = 500;
		FOR(i,0,319) lazy[i] = 999;
		for (int i = 0; i < m; ++i) {
			cin >> l >> r >> c;
			lb = Ceil(l,bsize);
			rb = Ceil(r,bsize);
			if(lb == rb) {
				for (int i = l; i <= r; ++i) cost[i] = min(lazy[lb],min(cost[i],c));
			}
			else {
				for (int i = l; i % bsize != 1 && i <= n; ++i) {
					cost[i] = min(lazy[lb],min(cost[i],c));
					l++;
				}
				for (int i = r; i % bsize != 0; --i) {
					cost[i] = min(lazy[rb],min(cost[i],c));
					r--;
				}
				lb = Ceil(l,bsize);
				rb = Ceil(r,bsize);
				if(lb <= rb) {
					for (int i = lb; i <= rb; ++i) {
						if(lazy[i] > c ) lazy[i] = c ;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			ans += (ll)arr[i];
			if(arr[i] >= 0) continue;
			tmp = min(cost[i],lazy[Ceil(i,bsize)]);
			if(tmp != 500) {
				newarr[++nsize] = (ll)(-arr[i]);
				value[nsize] = tmp;
			}
		}
		ans += knapsack(nsize,k);
		cout << ans << endl;
	}
    return 0;
}
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



ll matrix[3500][3500];
ll horizontal[3500][3500];
ll vertical[35000][3500];
ll dp1[3500][3500];


inline void Refresh() {
    for (int i = 0; i < 3500; ++i) {
    	for (int j = 0; j < 3500; ++j) {
    		matrix[i][j] = 1;
    	}
    }
	fill(horizontal,0);
	fill(vertical,0);
	fill(dp1,0);
}

int main()
{
	ll k,x,y,z,n,m,t,r,c;
	freopen("in.txt","r",stdin);
	cin >> t;
	int tt = 1;
	while(t--)
	{
		Refresh();
		printf("Case #%d: ",tt);
		tt++;
		cin >> r >> c >> k;
		for(int i = 0; i < k;i++)
		{
			cin >> x >> y;
			matrix[x][y]=0;
		}
		//continue;
		for(int i = 0; i < r;i++)
		{
			for(int j = c-1;j >= 0;j--)
			{
				if(matrix[i][j]==0)
					continue;
				if(j==c-1)
					{
						horizontal[i][j]=1;
						continue;
					}
				horizontal[i][j] = 1 + horizontal[i][j+1];
			}
		}
		for(int i=r-1;i>=0;i--)
		{
			for(int j=0;j<c;j++)
			{
				if(matrix[i][j]==0)
					continue;
				if(i==r-1)
				{
					vertical[i][j]=1;
					continue;
				}
				vertical[i][j]=1+vertical[i+1][j];
			}
		}
		ll count1=0;
		for(int i=r-1;i>=0;i--)
		{
			for(int j=c-1;j>=0;j--)
			{
				if(matrix[i][j]==0) continue;
				if(i==r-1 || j==c-1)
				{
					dp1[i][j]=1;
					count1+=1;
					continue;
				}
				z=dp1[i+1][j+1];
				++z;
				y = min(vertical[i][j],horizontal[i][j]);
				dp1[i][j] = min(z,y);
				count1 += dp1[i][j];
			}
		}
		cout << count1 << endl;
	}

	return 0;
}
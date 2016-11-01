#include <bits/stdc++.h>
using namespace std;

# define for1(i,k,n)              for(long long i=k;i<n;i++)
# define for2(i,k,n)              for(long long i=k;i<=n;i++)
# define Min(x,y)                   ((x)<(y)?(x):(y))
# define Max(x,y)                   ((x)>(y)?(x):(y))
# define INF                       (long long int) 1e15+10
#define All(a)                      a.begin(), a.end()
# define Abs(x)                 (x>=0?x:-x)
# define MOD                        1000000007
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define s(n)                        scanf("%d",&n);
#define sc(n)                       scanf("%c",&n);
#define sl(n)                       scanf("%lld",&n);
#define sf(n)                       scanf("%lf",&n);
#define ss(n)                       scanf("%s",n);

# define pr1(n)                     printf("%lld ",n);
# define pr2(n)                     printf("%lld\n",n);
# define pri(n)                     printf("%d",n);
# define prc(n)                     printf("%c",n);
# define prs(n)                     printf("%s",n);

# define srt(v)                     sort(v.begin(),v.end());
# define rt(n)                      return n;
#define bit(x,i) (x&(1<<i))
#define PI 3.1415926535897932384626




typedef long long int ll;

ll matrix[30][30];

ll check(ll r, ll c)
{    ll i,j;
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(matrix[i][j]==0)
				continue;
			if(matrix[i][j+1]==1 && matrix[i][j-1]==1)
				return -1;
			if(matrix[i-1][j]==1 && matrix[i+1][j]==1)
				return -1;
		}
	}
	return 1;
}


int main()
{
	ll i,j,k,x,y,z,n,m,t,r,c;
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	// ofstream fout;
	// fout.open("out2.txt");
	sl(t)
	for1(t1,1,t+1)
	{
		printf("Case #%lld: ",t1);
		sl(r)
		sl(c)
		for(i=0;i<30;i++)
		{
			for(j=0;j<30;j++)
				matrix[i][j]=0;
		}
		ll limit=r*c;
		ll number=1<<limit;
		ll count_max=0;
		for1(k,0,number)
		{
			ll count_now=0;
			for(i=1;i<=r;i++)
			{
				ll lower_index=c*(i-1);
				for(j=1;j<=c;j++)
				{
					ll index=lower_index+j-1;
					z=1<<index;
					ll q=z&k;
					//cout<<lower_index<<" "<<index<<" "<<q<<endl;
					//z=1<<index;
					if(q==0)
						matrix[i][j]=0;
					else
						{
							++count_now;
							matrix[i][j]=1;
						}
				}
			}
			/*cout<<"Hi"<<" "<<k<<endl;
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
					cout<<matrix[i][j]<<" ";
				cout<<endl;
			}*/
			ll x=check(r,c);
			if(x==1)
			{
				count_max=Max(count_max,count_now);
			}
			
		}
		cout<<count_max<<endl;
	}

	return 0;
}
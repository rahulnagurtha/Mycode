#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define ll long long

int a[110][110];
int mark[110][110];
priority_queue<pair<int,pair<int,int> > > q;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
bool check(int i,int j,int n,int m)
{
	if(i<0 || i>=n || j<0 || j>=m)
		return 0;
	return 1;
}
int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("B1.txt","w",stdout);
	int t,n,m,i,j;
	sd(t);
	for(int tt=1;tt<=t;++tt)
	{
		sd(n);sd(m);
		int ans=0;
		for(i=0;i<n;++i)
			clr(mark[i]);
		for(i=0;i<n;++i)
			for(j=0;j<m;++j)
				sd(a[i][j]);
		for(i=0;i<n;++i)
			q.push(MP(-a[i][0],MP(i,0)));
		for(i=0;i<n;++i)
			q.push(MP(-a[i][m-1],MP(i,m-1)));
		for(i=0;i<n;++i)
			q.push(MP(-a[0][i],MP(0,i)));
		for(i=0;i<n;++i)
			q.push(MP(-a[n-1][i],MP(n-1,i)));
		while(!q.empty())
		{
			pair<int,pair<int,int> > p=q.top();
			while(!q.empty())
			{
				pair<int,pair<int,int> > p1=q.top();
				if(p1.F<p.F)
					break;
				q.pop();
				if(mark[p1.S.F][p1.S.S])
					continue;
				mark[p1.S.F][p1.S.S]=1;
				ans+=(p1.F-p.F);
				cout << p1.F << " - " << p.F << endl;
				for(i=0;i<4;++i)
				{
					int i1=p1.S.F+di[i];
					int j1=p1.S.S+dj[i];
					if(check(i1,j1,n,m))
						q.push(MP(-a[i1][j1],MP(i1,j1)));
				}
			}	
		}
		printf("Case #%d: %d\n",tt,ans);
		// printf("%d\n",ans);
	}
}
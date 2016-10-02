/*
ID:		ganeshk2
lang:	cpp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<ii>		vii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
#define pb			push_back
#define mp			make_pair
#define rep(i,b,a)  for(i=a;i<b;i++)
#define f(i,n)      rep(i,n,0)
#define tr(it,container) for(auto it=container.begin();it!=container.end();++it)
#define all(a)		a.begin(),a.end()
#define sortall(a)	sort(all(a))
#define mem(a,x)	memset(a,x,sizeof(a))
#define MOD			1000000007
#define PI          3.1415926535897932384626
#define F			first
#define S			second
#define endl		'\n'
#define maxn 100010


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,m,p,i,j;
	cin>>n>>m>>p;
	int a[n][m],val[n][m];
	vii mymap[p+1];
	f(i,n) f(j,m) {cin>>a[i][j];mymap[a[i][j]].pb(mp(i,j));val[i][j]=MOD;}
	int x=0,y=0,curr=1;
	f(i,mymap[curr].size())
	{
		int nx=mymap[curr][i].F, ny=mymap[curr][i].S;
		val[nx][ny] = nx+ny;
	}
	curr++;
	while(curr!=p+1)
	{
		f(i,mymap[curr].size())
		{
			int nx = mymap[curr][i].F, ny = mymap[curr][i].S;
			f(j,mymap[curr-1].size())
			{
				int mx = mymap[curr-1][j].F, my = mymap[curr-1][j].S;
				val[nx][ny] = min(val[nx][ny],val[mx][my]+abs(nx-mx) + abs(ny-my));
			}
		}
		curr++;
	}
	f(i,n) {f(j,m) cout<<val[i][j]<<" ";cout<<endl;}
	f(i,n) f(j,m) if(a[i][j]==p) {cout<<val[i][j];return 0;}

return 0;
}
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
#define si(x)		scanf("%d",&x)
#define sl(x)		scanf("%I64d",&x)
#define ss(s)		scanf("%s",s)
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

/*ll powe(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&(1LL))res=(res*a)%MOD;a=a*a%MOD;}return res;}
int scan_d(){
	int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ll scan_lld(){
	int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
*/

#define maxn 1010
#define LN 12

vector<vi> adjlist(maxn);
int pa[LN][maxn],depth[maxn];

void dfs(int u,int prev)
{
	int i;
	pa[0][u] = prev;
	depth[u] = ((prev == -1)?(0):(depth[prev] + 1));
	f(i,adjlist[u].size())
	{
		int v = adjlist[u][i];
		if(v != prev)
			dfs(v,u);
	}
}

int LCA(int u,int v)
{
	int i;
	if(depth[u] < depth[v])
		return LCA(v,u);

	int diff = depth[u] - depth[v];

	// ancestor of u on same level with v
	f(i,LN)
		if((diff>>i) & 1)
			u = pa[i][u];

	if(u != v)
	{
		for(i = LN-1; i >= 0; i--)
			if(pa[i][u] != pa[i][v]) u = pa[i][u],v = pa[i][v];

		u = pa[0][u];
	}
	return u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	int cnt = 0;
	while(t--)
	{
		cnt++;
		cout << "Case " << cnt << ":" << endl;
		int watch[1010] = {0};
		for (int i = 0; i < 1010; ++i) {
			adjlist[i].clear();
		}
		mem(depth,0);
		int n,m,i,j,x,y,num;
		cin>>n;
		for (int k = 0; k < n; ++k) {
			cin >> num;
			for (int l = 0; l < num; ++l) {
				cin >> y;
				adjlist[k+1].pb(y);
				adjlist[y].pb(k+1);
				watch[y]++;
			}
		}
		int root;
		for (int k = 1; k <= n; ++k) {
			if(watch[k] == 0) {
				root = k;
				break;
			}
		}
		mem(pa,-1);
		//assuming tree is rooted at 1
		dfs(root,-1);
		// pa[i][j] is 2^j ancestor of node i
		rep(i,LN,1)
		{
			f(j,maxn)
			{
				if(pa[i-1][j]!=-1) pa[i][j] = pa[i-1][ pa[i-1][j] ];
			}
		}
		int q,u,v;
		cin >> q;
		for (int k = 0; k < q; ++k) {
			cin >> u >> v;
			cout << LCA(u,v) << endl;
		}
	}

return 0;
}
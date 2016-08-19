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


#define N 5005


int arr[N][N];
int done[N];
int a[N];
int ti,cycle;
int rem[N];

struct Node
{
	VI a;
	void createGraph()
	{
		int n = a.size();
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				arr[a[i]][a[j]] = 1;
	}
}professor[N];



void dfs(int u)
{
	done[u] = 1;
	rem[u] = 1;
	for (int i = 1; i < ti + 1; ++i) {
		if (arr[u][i])
		{
			if (done[i])
			{
				if (rem[i])
					cycle = 1;
			}
			else dfs(i);
		}
	}
	rem[u] = 0;
}

void solve(int n)
{
	int m,i,temp=0;
	map<string, int> A;
	ti = 0;
	A.clear();
	string s;
	cin.ignore();
	fill(arr,0);
	for (int i = 0; i < n; ++i) professor[i].a.clear();
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s);
		istringstream ss(s);
		while(getline(ss, s, ','))
		{
			if (A.find(s) == A.end()) A[s] = ++ti;
			professor[i].a.pb(A[s]);
		}
		professor[i].createGraph();
	}
	fill(done,0);
	cycle = 0;
	for (int i = 1; i < ti + 1; ++i)
	{
		if (done[i]==0)
		{
			fill(rem,0);fill(done,0);
			dfs(i);
			if(cycle)
			{
				temp = 1;
				break;
			}
		}
	}
	if(temp) cout << "ORDER VIOLATION\n";
	else cout << "ORDER EXISTS\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}
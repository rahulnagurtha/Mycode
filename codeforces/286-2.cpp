#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	107


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



PII node[N][N];	//colour,idx
int u,v;
int a,b,c;

void makeSet() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			node[i][j].FF = j;
			node[i][j].SS = 0;
		}
	}
	return;
}

int findSet(int colour,int val) {
	if(node[colour][val].FF == val) return val;
	else {
		node[colour][val].FF = findSet(colour,node[colour][val].FF);
		return node[colour][val].FF;
	}
}

void combine(int colour,int src,int target) {
	int one = findSet(colour,src);
	int two = findSet(colour,target);
	if(one == two) return;
	if(node[colour][one].SS == node[colour][two].SS) {
		node[colour][one].FF = two;
		node[colour][two].SS++;
	}
	else if(node[colour][one].SS > node[colour][two].SS) {
		node[colour][two].FF = one;
	}
	else {
		node[colour][one].FF = two;
	}
}

int n,m;


int main()
{
	makeSet();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		combine(c,a,b);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> u >> v;
		int ans = 0;
		for (int j = 1; j <= m; ++j) {
			// cout << j << " - " << findSet(j,u) << " " << findSet(j,v) << endl;
			if(findSet(j,u) == findSet(j,v)) ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
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
#define N                     	100007


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


inline void Refresh() {
    
}

map<string,int> depth;
map<char,char> abrakadabra;

int main()
{
	int ans = 1;
	depth["polycarp"] = 1;
	for (int i = 0; i < 26; ++i) {
		abrakadabra['a' + i] = 'a' + i;
		abrakadabra['A' + i] = 'a' + i;
	}
	for (int i = 0; i < 10; ++i) {
		abrakadabra['0' + i] = '0' + i;
	}
	int n;
	string name1,name2,garbage;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name1 >> garbage >> name2;
		for (int j = 0; j < name1.size(); ++j) name1[j] = abrakadabra[name1[j]];
			for (int j = 0; j < name2.size(); ++j) name2[j] = abrakadabra[name2[j]];
		depth[name1] = depth[name2] + 1;
		ans = max(ans,depth[name1]);
	}
	cout << ans << endl;
    return 0;
}
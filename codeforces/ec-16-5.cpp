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
#define INF 					10000000000000007LL
#define N                     	10000007


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



bool visited[2*N];
ll disSofar[2*N];
priority_queue<PLL,VOLL,greater<PLL> > Q;


int main()
{	
	ll ans;
	ll n,x,y;
	cin >> n >> x >> y;
	for (int i = 0; i < 2*N; ++i) {
		disSofar[i] = INF;
	}
	disSofar[0] = 0;
	Q.push(mp(0,0));
	while(!Q.empty()) {
		PLL cur = Q.top();
		Q.pop();
		if(cur.SS == n) break;
		if(visited[cur.SS]) continue;
		visited[cur.SS] = true;
		//try to delete
		if(cur.SS > 0 && disSofar[cur.SS - 1] > disSofar[cur.SS] + x) {
			disSofar[cur.SS - 1] = disSofar[cur.SS] + x;
			Q.push(mp(disSofar[cur.SS - 1],cur.SS - 1));
		}
		//try to add
		if(cur.SS < n && disSofar[cur.SS + 1] > disSofar[cur.SS] + x) {
			disSofar[cur.SS + 1] = disSofar[cur.SS] + x;
			Q.push(mp(disSofar[cur.SS + 1],cur.SS + 1));
		}
		//try to double
		if(cur.SS < n && disSofar[2*cur.SS] > disSofar[cur.SS] + y) {
			disSofar[2*cur.SS] = disSofar[cur.SS] + y;
			Q.push(mp(disSofar[2*cur.SS],2*cur.SS));
		}
	}
	cout << disSofar[n] << endl;
    return 0;
}
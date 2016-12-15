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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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


int main()
{
	int n;
	int a[1005];
	int sereja = 0,dima = 0;
	cin >> n;
	int lft = 0,ryt = n - 1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if(i%2 == 0) {
			if(a[lft] > a[ryt]) {
				sereja += a[lft];
				lft++;
			}
			else {
				sereja += a[ryt];
				ryt--;
			}
		}
		else {
			if(a[lft] > a[ryt]) {
				dima += a[lft];
				lft++;
			}
			else {
				dima += a[ryt];
				ryt--;
			}
		}
	}
	cout << sereja << " " << dima << endl;
    return 0;
}
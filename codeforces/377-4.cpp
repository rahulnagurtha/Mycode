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

int n,m;
int d[N];
int a[N];

inline bool isPossible(int daysLeft) {
	bool isAssigned[N];
	int newSchedule[N];
	fill(newSchedule,0);
	fill(isAssigned,false);
	for (int i = daysLeft; i >= 1; --i) {
		if(d[i] != 0 && !isAssigned[d[i]]) {
			isAssigned[d[i]] = true;
			newSchedule[i] = d[i];
		}
	}
	for (int i = 1; i <= m; ++i) {
		if(!isAssigned[i]) return false;
	}
	int numOfPrepDays = 0;
	for (int i = 1; i <= daysLeft; ++i) {
		if(newSchedule[i] != 0) {
			if(numOfPrepDays < a[newSchedule[i]]) return false;
			else {
				numOfPrepDays -= a[newSchedule[i]];
			}
		}
		else numOfPrepDays++;
	}
	return true;
}


int main()
{
	si2(n,m);
	for (int i = 1; i <= n; ++i) {
		si(d[i]);
	}
	for (ll i = 1; i <= m; ++i) {
		si(a[i]);
	}
	int l = 1,r = n;
	while(l < r) {
		int mid = (l + r)/2;
		if(isPossible(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	if(isPossible(l)) {
		printf("%d\n",l);
	}
	else printf("-1\n");
    return 0;
}
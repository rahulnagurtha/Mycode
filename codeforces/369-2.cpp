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


int main()
{
    int n;
    int row = -1;
    int column = -1;
    ll a[505][505];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> a[i][j];
    		if(a[i][j] == 0) {
    			row = i;
    			column = j;
    		}
    	}
    }
    if(n == 1) printf("1\n");
    else {
    	ll presentSum = 0;
    	ll futureSum = 0;
    	if(row != 1) {
    		for (int i = 1; i <= n; ++i) {
    			futureSum += a[1][i];
    		}
    	}
    	else {
    		for (int i = 1; i <= n; ++i) {
    			futureSum += a[2][i];
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
			presentSum += a[row][i];
		}
		if(futureSum - presentSum <= 0) {
			printf("-1\n");
			return 0;
		}
		a[row][column] = futureSum - presentSum;
		bool isMagic = true;
		for (int i = 1; i <= n; ++i) {
			ll rowSum = 0;
			for (int j = 1; j <= n; ++j) {
				rowSum += a[i][j];
			}
			if(rowSum != futureSum) isMagic = false;
		}
		for (int j = 1; j <= n; ++j) {
			ll columnSum = 0;
			for (int i = 1; i <= n; ++i) {
				columnSum += a[i][j];
			}
			if(columnSum != futureSum) isMagic = false;
		}
		ll diagSum = 0;
		for (int i = 1; i <= n; ++i) {
			diagSum += a[i][i];
		}
		if(diagSum != futureSum) isMagic = false;
		diagSum = 0;
		for (int i = 1; i <= n; ++i) {
			diagSum += a[i][n-i+1];
		}
		if(diagSum != futureSum) isMagic = false;
		if(isMagic) cout << a[row][column] << endl;
		else printf("-1\n");
    }
    return 0;
}
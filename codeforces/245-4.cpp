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
#define N                     	1007


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



int n,m;
int a[N][N];
int lahubTo[N][N];
int lahubFrom[N][N];
int lahubinaTo[N][N];
int lahubinaFrom[N][N];


void processLahub() {
	for (int j = m; j > 0; --j) {
		for (int i = n; i > 0; --i) {
			lahubFrom[i][j] = a[i][j] + max(lahubFrom[i+1][j],lahubFrom[i][j+1]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			lahubTo[i][j] = a[i][j] + max(lahubTo[i-1][j],lahubTo[i][j-1]);
		}
	}
	return;
}

void processLahubina() {
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j > 0; --j) {
			lahubinaFrom[i][j] = a[i][j] + max(lahubinaFrom[i-1][j],lahubinaFrom[i][j+1]);
		}
	}
	for (int i = n; i > 0; --i) {
		for (int j = 1; j <= m; ++j) {
			lahubinaTo[i][j] = a[i][j] + max(lahubinaTo[i+1][j],lahubinaTo[i][j-1]);
		}
	}
	return;
}

void compute() {
	int up,down,Lahubryt,Lahubinaryt;
	int ans = 0,tmp;
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < m; ++j) {
			tmp = lahubTo[i-1][j] + lahubFrom[i+1][j] + lahubinaTo[i][j-1] + lahubinaFrom[i][j+1];
			tmp = max(tmp,lahubinaTo[i+1][j] + lahubinaFrom[i-1][j] + lahubTo[i][j-1] + lahubFrom[i][j+1]);
			ans = max(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return;
}

int main()
{
    si2(n,m);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		si(a[i][j]);
    	}
    }
    processLahub();
    processLahubina();
    compute();
    return 0;
}
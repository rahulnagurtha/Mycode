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

int n,k;
int a[300005];

int main()
{
	int ans = 0;
	int lftIdx = -1;
	int rytIdx = -2;
	si2(n,k);
	for (int i = 0; i < n; ++i) {
		si(a[i]);
	}
	int numZeroes = 0;
	for (int l = 0,r = 0; l < n; ++l) {
		while(numZeroes <= k && r < n) {
			r++;
			if(a[r - 1] == 0) numZeroes++;
			if(numZeroes > k) break;
			else if(r - l > ans){
				lftIdx = l;
				rytIdx = r - 1;
				ans = rytIdx - lftIdx + 1;
			}
		}
		if(a[l] == 0) numZeroes--;
	}
	cout << ans << endl;
	for (int i = 0; i < n; ++i) {
		if(lftIdx <= i && i <= rytIdx) a[i] = 1;
		printf("%d ",a[i]);
	}
	printf("\n");
    return 0;
}
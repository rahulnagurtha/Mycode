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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

char a[(1 << 9) + 5][(1 << 9) + 5];

void fillup(int k) {
	int till = 1 << k;
	//upper right
	for (int i = 1; i <= till/2; ++i) {
		for (int j = 1 + till/2; j <= till; ++j) {
			a[i][j] = a[i][j - till/2];
		}
	}
	//lower left
	for (int i = 1 + till/2; i <= till; ++i) {
		for (int j = 1; j <= till/2; ++j) {
			a[i][j] = a[i-till/2][j];
		}
	}
	//lower right
	for (int i = 1 + till/2; i <= till; ++i) {
		for (int j = 1 + till/2; j <= till; ++j) {
			a[i][j] = ( (a[i-till/2][j-till/2] == '*') ? '+' : '*' );
		}
	}
	return;
}

int main()
{
	int n;
	a[1][1] = '+';
	cin >> n;
	for (int i = 1; i <= 9; ++i) fillup(i);
	int till = 1 << n;
	for (int i = 1; i <= till; ++i) {
		for (int j = 1; j <= till; ++j) {
			cout << a[i][j]; 
		}
		cout << "\n";
	}
    return 0;
}

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


int n,p,q;
string a;


int main()
{
	int temp1 = -1,temp2 = -1;
	cin >> n >> p >> q;
	cin >> a;
	for (int i = 0; i <= n; ++i) { 			//	i*p + j*q = n
		if(n - p*i >= 0 && (n-p*i) % q == 0) {
			temp1 = i;
			temp2 = (n-p*i)/q;
		}
	}
	if(temp1 == -1 && temp2 == -1) {
		printf("-1\n");
	}
	else {
		cout << temp1 + temp2 << endl;
		for (int i = 0; i < temp1*p; ++i) {
			cout << a[i];
			if( (i+1) % p == 0) printf("\n");
		}
		for (int i = p*temp1; i < a.size(); ++i) {
			cout << a[i];
			if( (i - p*temp1 + 1) % q == 0) printf("\n");
		}
	}
    return 0;
}

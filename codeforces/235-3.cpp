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


char a[5000000];

int main()
{
    int n,m;
    cin >> n >> m;
    if( m < n - 1 || m > 2*(n+1)) {
    	cout << "-1" << endl;
    	return 0;
    }
    if(n == m + 1) {
    	for (int i = 0; i < n+m; ++i) {
    		if(i%2 == 0) printf("0");
    		else printf("1");
    	}
    	return 0;
    }
    if(n == m ) {
    	for (int i = 0; i < n+m; ++i) {
    		if(i%2 == 0) printf("1");
    		else printf("0");
    	}
    	return 0;
    }
    if(n + 1 == m) {
    	for (int i = 0; i < n+m; ++i) {
    		if(i%2 == 0) printf("1");
    		else printf("0");
    	}
    	return 0;
    }
    for (int i = 0; i < 3000000; ++i) {
    	a[i] = '*';
    }
    int tmp = 2;
    for (int i = 0; i < n; ++i) {
    	a[tmp] = '0';
    	tmp += 3;
    }
    tmp = 0;
    for (int i = 0; i < n + 1; ++i) {
    	a[tmp] = '1';
    	tmp += 3;
    }
    tmp = m;
    tmp = tmp - (n+1);
    int tmp1 = 1;
    for (int i = 0; i < tmp; ++i) {
    	a[tmp1] = '1';
    	tmp1 += 3; 
    }
    for (int i = 0; i < 3000000; ++i) {
    	if(a[i] != '*') cout << a[i];
    }
    return 0;
}

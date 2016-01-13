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

int dp[105][105];
int n,a[105];



int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	int LESS,MORE;
    	si(n);
    	for (int i = 1; i <= n; ++i) si(a[i]);

    	for (int i = 1; i <= n; ++i) {
    		LESS = MORE = 0;
    		for (int j = 1; j <= i-1; ++j) {
    		 	if(a[j] < a[i]) LESS++;
    		 	if(a[j] > a[i]) MORE++;
    		}
    		for (int j = i+1; j <= n; ++j) {
    			if(a[j] < a[i]) LESS++;
    		 	if(a[j] > a[i]) MORE++;
    		}
    		dp[i][i] = min(LESS,MORE); 
    	}
        
    	for (int i = 2; i <= n; ++i) {
    		for (int j = 1; j+i-1 <= n ; ++j) {
    			//for left
    			LESS = MORE = 0;
    			for (int k = 1; k <= j-1; ++k) {
    				if(a[k] < a[j]) LESS++;
    				if(a[k] > a[j]) MORE++;
    			}
    			for (int k = j+i; k <= n; ++k) {
    				if(a[k] < a[j]) LESS++;
    				if(a[k] > a[j]) MORE++;
    			}
    			dp[j][j+i-1] = dp[j+1][j+i-1] + min(LESS,MORE);
    			//for right
    			LESS = MORE = 0;
    			for (int k = 1; k <= j-1; ++k) {
    				if(a[k] < a[j+i-1]) LESS++;
    				if(a[k] > a[j+i-1]) MORE++;
    			}
    			for (int k = j+i; k <= n; ++k) {
    				if(a[k] < a[j+i-1]) LESS++;
    				if(a[k] > a[j+i-1]) MORE++;
    			}
    			dp[j][j+i-1] = min(dp[j][j+i-1],dp[j][j+i-2]+min(LESS,MORE));
    		}
    	}

    	
    	printf("%d\n",dp[1][n]);
    }
    return 0;
}

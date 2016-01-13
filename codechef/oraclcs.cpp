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
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

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

int n;
string a[101];



int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	int cnt_a,cnt_b,min_a = 101,min_b = 101;
    	cin >> n ;
    	int ans = 1000;
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		cnt_a = 0;
    		cnt_b = 0;
    		for (int j = 0; j < a[i].size(); ++j) {
    			if(a[i][j] == 'a') cnt_a++;
    			else cnt_b++; 
    		}
    		min_a = min(min_a,cnt_a);
    		min_b = min(min_b,cnt_b);
    	}
    	ans = min(min_a,min_b);
    	cout << ans << endl;
    }
    return 0;
}

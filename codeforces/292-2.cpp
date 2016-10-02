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
    int n,m;
    int g,b;
    int tmp;
    bool isBoyHappy[105];
    bool isGirlHappy[105];
    fill(isGirlHappy,false);
    fill(isBoyHappy,false);
    cin >> n >> m;
    cin >> b;
    for (int i = 0; i < b; ++i) {
    	cin >> tmp;
    	isBoyHappy[tmp] = true;
    }
    cin >> g;
    for (int i = 0; i < g; ++i) {
    	cin >> tmp;
    	isGirlHappy[tmp] = true;
    }
    while(1) {
    	int cnt = 0;
	    for (int i = 1; i <= n*m/__gcd(n,m); ++i) {
	    	int boy = i % n;
	    	int girl = i % m;
	    	if(isBoyHappy[boy] || isGirlHappy[girl]) {
	    		if(!isBoyHappy[boy]) {
	    			isBoyHappy[boy] = true;
	    			cnt++;
	    		}
	    		else if(!isGirlHappy[girl]) {
	    			isGirlHappy[girl] = true;
	    			cnt++;
	    		}
	    	}
	    }
	    if(cnt == 0) break;
	}
	for (int i = 0; i < n; ++i) {
		if(!isBoyHappy[i]) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		if(!isGirlHappy[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
    return 0;
}
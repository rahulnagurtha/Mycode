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



int main()
{
    int n,one,two;
    deque<int> Q;
    cin >> n;
    Q.pb(0);
    Q.pb(1);
    for (int i = 1; i < n; ++i) {
    	Q.pb(1);
    	while(1) {
    		one = Q.back();
	    	Q.pop_back();
	    	two = Q.back();
	    	Q.pop_back();
	    	if(one == two) {
	    		Q.pb(one+1);
	    	}
	    	else {
	    		Q.pb(two);
	    		Q.pb(one);
	    		break;
	    	}
    	}
    }
    Q.pop_front();
    while(Q.size() > 0) {
    	cout << Q.front() << " ";
    	Q.pop_front();
    }
    printf("\n");
    return 0;
}

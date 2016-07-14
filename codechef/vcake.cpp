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
    int t;
    cin >> t ;
    while(t--) {
    	ll r,c,m,k,j;
    	cin >> r >> c >> m >> j >> k;
    	if(m + j + k != r*c) {
    		printf("No\n");
    		continue;
    	}
    //C constant
		//m
		if (m%c == 0) {
			ll l1 = r - m/c;
			if (k%l1 == 0 && j%l1 == 0 && l1*c == k + j) {
				printf("Yes\n");
				continue;
			}
		}

		//k
		if (k%c == 0) {
			ll l1 = r - k/c;
			if (m%l1 == 0 && j%l1 == 0 && l1*c == m + j) {
				printf("Yes\n");
				continue;
			}
		}
		//j    	
		if (j%c == 0) {
			ll l1 = r - j/c;
			if (m%l1 == 0 && k%l1 == 0 && l1*c == m + k) {
				printf("Yes\n");
				continue;
			}
		}
	//R constant
    	//m
		if (m%r == 0) {
			ll l1 = c - m/r;
			// cout << k%l1  << j%l1 << endl; 
			if (k%l1 == 0 && j%l1 == 0 && l1*r == k + j) {
				printf("Yes\n");
				continue;
			}
		}

		//k
		if (k%r == 0) {
			ll l1 = c - k/r;
			if (m%l1 == 0 && j%l1 == 0 && l1*r == m + j) {
				printf("Yes\n");
				continue;
			}
		}
		//j    	
		if (j%r == 0) {
			ll l1 = c - j/r;
			if (m%l1 == 0 && k%l1 == 0 && l1*r == m + k) {
				printf("Yes\n");
				continue;
			}
		}
	//r constant
		if(m%r == 0 && j%r == 0 && k%r == 0) {
			if(m/r + j/r + k/r == c) {
				printf("Yes\n");
				continue;
			}
		}
	//c constant
		if(m%c == 0 && j%c == 0 && k%c == 0) {
			if(m/c + j/c + k/c == r) {
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
    }
    return 0;
}

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
#define N                     	500007


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

int n;
int a[N];
stack<int> S;
int l[N],r[N];
int maximum[N];

int main()
{
    si(n);
    for (int i = 1; i <= n; ++i) {
    	si(a[i]);
    }
    //filling r[]
    for (int i = 1; i <= n; ++i) {
    	while(!S.empty() && a[S.top()] > a[i]) {
    		r[S.top()] = i;
    		S.pop();
    	}
    	S.push(i);
    }
    while(!S.empty()) {
		r[S.top()] = n + 1;
		S.pop();
	}
	//filling l[]
	for (int i = n; i > 0; --i) {
    	while(!S.empty() && a[S.top()] > a[i]) {
    		l[S.top()] = i;
    		S.pop();
    	}
    	S.push(i);
    }
    while(!S.empty()) {
		l[S.top()] = 0;
		S.pop();
	}
	//traverse to find the intervals
	for (int i = 1; i <= n; ++i) {
		maximum[r[i] - l[i] - 1] = max(maximum[r[i] - l[i] - 1],a[i]);
	}
	//traverse to find the maximums
	int tmp = 0;
	for (int i = n; i > 0; --i) {
		tmp = max(tmp,maximum[i]);
		maximum[i] = tmp; 
	}
	for (int i = 1; i <= n; ++i) {
		cout << maximum[i] << " ";
	}
	printf("\n");
    return 0;
}
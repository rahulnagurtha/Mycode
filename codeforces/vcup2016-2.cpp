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
    int n;
    int R = 0,G = 0,B = 0;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i) {
    	if(a[i] == 'R') R++;
    	if(a[i] == 'G') G++;
    	if(a[i] == 'B') B++;
    }
    if((R > 0) && (G > 0) && (B > 0)) {
    	printf("BGR\n");
    }
    else if((R == 0) && (G == 0)) {
    	printf("B\n");
    }
    else if((B == 0) && (G == 0)) {
    	printf("R\n");
    }
    else if((R == 0) && (B == 0)) {
    	printf("G\n");
    }
    else if(R == 0) {
    	if((B == 1) && (G == 1)) {
    		printf("R\n");
    	}
    	else if((B > 1) && (G == 1)) {
    		printf("GR\n");
    	}
    	else if((B == 1) && (G > 1)) {
    		printf("BR\n");
    	}
    	else {
    		printf("BGR\n");
    	}
    }
    else if(B == 0) {
    	if((R == 1) && (G == 1)) {
    		printf("B\n");
    	}
    	else if((R > 1) && (G == 1)) {
    		printf("BG\n");
    	}
    	else if((R == 1) && (G > 1)) {
    		printf("BR\n");
    	}
    	else {
    		printf("BGR\n");
    	}
    }
    else if(G == 0) {
    	if((R == 1) && (B == 1)) {
    		printf("G\n");
    	}
    	else if((R > 1) && (B == 1)) {
    		printf("BG\n");
    	}
    	else if((R == 1) && (B > 1)) {
    		printf("GR\n");
    	}
    	else {
    		printf("BGR\n");
    	}
    }
    return 0;
}

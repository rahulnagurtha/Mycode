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


int a[1000001];
int value[5000001];

// Build with array [i,j]

void build(int node,int i,int j,bool XOR) {
	if(i>j) return;
	if(i==j) {						
		value[node] = a[i];
		return;
	}
	build(node*2,i,(i+j)/2,!XOR);
	build(node*2+1,1+(i+j)/2,j,!XOR);
	if(XOR) value[node] = (value[2*node] ^ value[2*node + 1]);
	else value[node] = (value[2*node] | value[2*node + 1]);
	return;
}

void upd(int node,int pos,int i,int j,int val,bool XOR) {
    if(i>j) return;
    if(i == j && i == pos) {			
        value[node] = val;
        return;
    }
    if(i <= pos && j >= pos) {
        upd(2*node,pos,i,(i+j)/2,val,!XOR);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val,!XOR);
        if(XOR) value[node] = (value[2*node] ^ value[2*node + 1]);
		else value[node] = (value[2*node] | value[2*node + 1]);
    	return;
    }
}


int main()
{
    int n,m,p,b;
    int levels;
    si2(levels,m);
    n = (1 << levels);
    for (int i = 1; i <= n; ++i) {
    	si(a[i]);
    }
    build(1,1,n,(levels%2+1)%2);
    // for (int i = 1; i < 8; ++i) {
    // 	cout << value[i] << " ";
    // }
    // printf("\n");
    for (int i = 0; i < m; ++i) {
    	si2(p,b);
    	upd(1,p,1,n,b,(levels%2+1)%2);
    	// for (int i = 1; i < 8; ++i) {
	    // 	cout << value[i] << " ";
	    // }
	    // printf("\n");
    	printf("%d\n",value[1]);
    }
    return 0;
}
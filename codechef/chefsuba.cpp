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

#define forup(i,a,b)            for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b)            for(int i = (a); (i) > (b); --(i))
#define rep(i,a)                for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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


int aux[2*N];


struct tree {
    int ma;
};


tree seg[10000001];
int a[2*N];

// Build with array [i,j]

void build(int node,int i,int j) {
    if(i>j) return;
    if(i==j) {                        
        seg[node].ma = a[i];
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    seg[node].ma = max(seg[node*2].ma,seg[1+node*2].ma);
    return;
}

int qmax(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return -2147483645;
    if(a >= i && b <= j) return seg[node].ma;
    int q1,q2;
    q1 = qmax(node*2, a, (a+b)/2, i, j);
    q2 = qmax(1+node*2, 1+(a+b)/2, b, i, j);
    int res = max(q1, q2);
    return res;
}

int n,k,p;
int prefixSum[2*N];

int main()
{
	string query;
	int l,r;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i) {
    	cin >> aux[i];
    	aux[i + n] = aux[i];
    }
    k = min(k,n);
    for (int i = 1; i <= 2*n; ++i) {
    	prefixSum[i] = prefixSum[i-1] + aux[i];
    }
    for (int i = 1; i <= 2*n - k + 1; ++i) {
    	a[i] = prefixSum[i + k - 1] - prefixSum[i - 1];
    }
    build(1,1,2*n);
    l = 1;
    r = n;
    cin >> query;
    for (int i = 0; i < query.size(); ++i) {
    	if(query[i] == '?') {
    		cout << qmax(1,1,2*n,l,l + n - k) << endl;
    	}
    	else {
    		if(l == 1) l = n;
    		else l--;
    		r = l + n - 1;
    	}
    }
    return 0;
}
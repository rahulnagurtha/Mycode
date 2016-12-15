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

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

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



struct tree {
    int ma;
};

tree seg[500001];

// Build with array [i,j]

void build(int node,int i,int j) {
    if(i>j) return;
    if(i==j) {                        
        seg[node].ma = 0;
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


void upd(int node,int pos,int i,int j,int val) {
    if(i>j) return;
    if(i==j&&i==pos) {            
        seg[node].ma = val;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].ma = max(seg[2*node].ma,seg[2*node+1].ma);
        return;
    }
}


VOII B;


int main()
{
	int ans = 0;
	int n;
	int tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		B.pb(mp(tmp,i + 1));
	}
	sort(B.begin(), B.end());
	for (int i = 0; i < B.size(); ++i) {
		int curLen = 1;
		if(B[i].SS != 1) curLen += qmax(1,1,n,1,B[i].SS - 1);
		upd(1,B[i].SS,1,n,curLen);
		ans = max(ans,curLen);
	}
	cout << ans << endl;
    return 0;
}
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


struct tree {
    int sum;
};

tree seg[500001];
int a[100001];

// Build with array [i,j]

void build(int node,int i,int j) {
    if(i>j) return;
    if(i==j) {                        
        seg[node].sum = 0;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    seg[node].sum = 0;
    return;
}



int qsum(int node,int a,int b,int i,int j) {
    if(a > b || a > j || b < i) return 0;
    if(a >= i && b <= j) return seg[node].sum;
    int q1,q2;
    q1 = qsum(node*2, a, (a+b)/2, i, j);
    q2 = qsum(1+node*2, 1+(a+b)/2, b, i, j);
    int res = q1 + q2;
    return res;
}

void upd(int node,int pos,int i,int j,int val) {
    if(i>j) return;
    if(i==j&&i==pos) {            
        seg[node].sum = val;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].sum = seg[2*node].sum + seg[1+2*node].sum;
        return;
    }
}

inline void refresh() {
	build(1,1,100000);
	return;
}


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	refresh();
    	int n,tmp;
    	VOII data;
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		cin >> tmp;
    		data.pb(mp(tmp,i));
    	}
    	sort(data.begin(), data.end());
    	reverse(data.begin(), data.end());
    	while(data.size() > 1) {
    		// cout << data << endl;
    		int val = data.back().FF;
    		int pos = data.back().SS - qsum(1,1,n,1,data.back().SS - 1);
    		int toRemove = (val/pos)*pos + pos;
    		while(data.size() > 0) {
    			PII last = data.back();
    			if(last.FF < toRemove) {
    				data.pop_back();
    				upd(1,last.SS,1,n,1);
    			}
    			else break;
    		}
    	}
    	if(data.size() == 0) cout << "Kushagra" << endl;
    	else cout << "Ladia" << endl;
    }
    return 0;
}
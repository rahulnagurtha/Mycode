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



ll n;
VL A;
VL mapped;
ll lft[10*N];
ll ryt[10*N];
VOLL aux;

struct tree {
    ll sum;
};

tree seg[5000001];

// Build with array [i,j]

void build(ll node,ll i,ll j) {
    if(i > j) return;
    if(i == j) {
        seg[node].sum = 0;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    seg[node].sum = 0;
    return;
}


ll qsum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;
    if(a >= i && b <= j) return seg[node].sum;
    ll q1,q2;
    q1 = qsum(node*2, a, (a+b)/2, i, j);
    q2 = qsum(1+node*2, 1+(a+b)/2, b, i, j);
    ll res = q1 + q2;
    return res;
}

void upd(ll node,ll pos,ll i,ll j,ll val) {
    if(i>j) return;
    if(i==j&&i==pos) {
        seg[node].sum = val;
        return;
    }
    if(i <= pos && j >= pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].sum = seg[2*node].sum + seg[1+2*node].sum;
        return;
    }
}



void compressEfficient(VL &source,VL &target) {
	target = source;
	VOLL tmp;
	for (ll i = 0; i < source.size(); ++i) {
		tmp.push_back(mp(source[i],i));
	}
	sort(tmp.begin(), tmp.end());
	ll lastGivenLabel = 1;
	ll lastNum = tmp[0].FF;
	target[tmp[0].SS] = 1;
	for (ll i = 1; i < tmp.size(); ++i) {
		if(tmp[i].FF == lastNum) {
			target[tmp[i].SS] = lastGivenLabel;
		}
		else {
			target[tmp[i].SS] = lastGivenLabel + 1;
			lastGivenLabel = target[tmp[i].SS];
			lastNum = tmp[i].FF;
		}
	}
	return;
}

void compress(VL &source,VL &target) {
    VL tmp = source;
    sort(tmp.begin(),tmp.end());
    for (int i = 0; i < source.size(); ++i) {
        ll label = (lower_bound(tmp.begin(),tmp.end(),source[i]) - tmp.begin());
        target.pb(label);
    }
    return;
}


bool cmp(PLL l,PLL r) {
    return l.FF > r.FF;
}

int main()
{
    ll tmp;
	// cin >> n;
    slli(n); 
	for (int i = 0; i < n; ++i) {
		// cin >> tmp;
        slli(tmp);
        A.pb(tmp);
	}
	onemore(A,mapped);
	for(int i = 0; i < A.size(); i++) {
        aux.pb(mp(A[i],i));
	}
	//fill lft
	sort(aux.begin(),aux.end(),cmp);
	build(1,1,n);
	for(int i = 0; i < aux.size(); i++) {
        lft[aux[i].SS] = qsum(1,1,n,1,aux[i].SS);
        upd(1,aux[i].SS + 1,1,n,1);
	}
	//fill ryt
    sort(aux.begin(),aux.end());
    build(1,1,n);
    for(int i = 0; i < aux.size(); i++) {
        ryt[aux[i].SS] = qsum(1,1,n,aux[i].SS + 2,n);
        upd(1,aux[i].SS + 1,1,n,1);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
        // cout << lft[i] << " " << ryt[i] << endl;
        ans += lft[i]*ryt[i];
	}
	// cout << ans << endl;
    plli(ans);
    return 0;
}

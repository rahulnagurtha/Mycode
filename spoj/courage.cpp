#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;




struct tree {
	ll mi;
	ll ma;
	ll sum;
};

tree seg[500001];

ll a[100001];

// Build with array [i,j]

void build(ll node,ll i,ll j) {
	if(i>j) return;
	if(i==j) {						
		seg[node].mi = seg[node].ma = seg[node].sum = a[i];
		return;
	}
	build(node*2,i,(i+j)/2);
	build(node*2+1,1+(i+j)/2,j);
	seg[node].ma = max(seg[node*2].ma,seg[1+node*2].ma);
	seg[node].mi = min(seg[node*2].mi,seg[1+node*2].mi);
	seg[node].sum = seg[node*2].sum + seg[1+node*2].sum;
	return;
}

ll qmin(ll node,ll a,ll b,ll i,ll j) {
	if(a > b || a > j || b < i) return 2147483645;
	if(a >= i && b <= j) return seg[node].mi;
	ll q1,q2;
	q1 = qmin(node*2, a, (a+b)/2, i, j);
	q2 = qmin(1+node*2, 1+(a+b)/2, b, i, j);
	ll res = min(q1, q2);
	return res;
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
        seg[node].ma += val;
        seg[node].mi += val;
        seg[node].sum += val;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].ma = max(seg[2*node].ma,seg[2*node+1].ma);
        seg[node].mi = min(seg[2*node].mi,seg[2*node+1].mi);
        seg[node].sum = seg[2*node].sum + seg[1+2*node].sum;
    	return;
    }
}



// main code begins now

int main()
{
    ll n,p,x,y;
    string action;
    slli(n);
    for (int i = 0; i < n; ++i) slli(a[i]);
    build(1,0,n-1);
	slli(p);
	for (int i = 0; i < p; ++i) {
		cin >> action >> x >> y;
		if(action == "EAT") {
			upd(1,y,0,n-1,-x);
		}
		else if(action == "GROW") {
			upd(1,y,0,n-1,x);
		}
		else {
			plli(qsum(1,0,n-1,x,y)-qmin(1,0,n-1,x,y));
		}
	}
    return 0;
}
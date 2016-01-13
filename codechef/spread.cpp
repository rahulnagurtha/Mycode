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



typedef long long int ll;

ll n,m,c;


struct tree {
    ll lazy;
};

tree part[5000001];


void build(ll node,ll i,ll j) {
    if(i>j) return;
    if(i==j) {                        
        part[node].lazy = c;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j); 
    part[node].lazy=0;
    return;
}

ll query_sum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;    
    if(part[node].lazy!= 0) { 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; 
            part[node*2+1].lazy += part[node].lazy;
        	part[node].lazy = 0;
        }
    }
    if(a == i && b == j) return part[node].lazy; 
    if(a <= i && (a+b)/2 >= j) return query_sum(node*2, a, (a+b)/2, i, j);    
    else return query_sum(1+node*2, 1+(a+b)/2, b, i, j);
}


void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {
    if(part[node].lazy != 0) { 
        if(a != b) {
            part[node*2].lazy += part[node].lazy; 
            part[node*2+1].lazy += part[node].lazy;
        	part[node].lazy = 0;
        }
    }
    if(a > b || a > j || b < i) return;
    if(a >= i && b <= j) {
        if(a != b) {
            part[node*2].lazy += (ll)value;
            part[node*2+1].lazy += (ll)value;
        }
        else part[node].lazy += (ll)value;
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value); 
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 
}



int main()
{
	char test;
	ll u,v,k,p;
    cin >> n >> m >> c;
    build(1,1,n);
    for (int i = 0; i < m; ++i) {
    	cin >> test;
    	if(test == 'S') {
    		cin >> u >> v >> k;
    		update_tree(1,1,n,u,v,k);
    	}
    	else {
    		cin >> p;
    		cout << query_sum(1,1,n,p,p) << "\n";
    	}
    }
    return 0;
}

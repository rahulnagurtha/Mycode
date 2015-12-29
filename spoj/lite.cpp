#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

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



struct tree {
    ll lazy;
    ll sum;
};

tree part[500001];

void build(ll node,ll i,ll j) {
    if(i>j) return;
    if(i==j) {                        
        part[node].sum = 0;
        part[node].lazy = 0;
        return;
    }
    build(node*2,i,(i+j)/2);
    build(node*2+1,1+(i+j)/2,j);
    part[node].sum=0;
    part[node].lazy=0;
    return;
}

ll query_sum(ll node,ll a,ll b,ll i,ll j) {
    if(a > b || a > j || b < i) return 0;
    part[node].lazy %= 2;
    if(part[node].lazy!= 0) {
        part[node].sum = (b-a+1) - (part[node].sum);
        if(a != b) {
            part[node*2].lazy += part[node].lazy;
            part[node*2+1].lazy += part[node].lazy;
        }
        part[node].lazy = 0;
    }
    if(a >= i && b <= j) return part[node].sum;
    ll q1,q2;
    q1=query_sum(node*2, a, (a+b)/2, i, j);
    q2=query_sum(1+node*2, 1+(a+b)/2, b, i, j); 
    ll res = q1+q2;    
    return res;
}

void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {
	part[node].lazy %= 2;
    if(part[node].lazy != 0) { 
        part[node].sum = (b-a+1) - (part[node].sum);
        if(a != b) {
            part[node*2].lazy += part[node].lazy;
            part[node*2+1].lazy += part[node].lazy;
        }
        part[node].lazy = 0;
    }
    if(a > b || a > j || b < i) return;
    if(a >= i && b <= j) { 
        part[node].sum = (b-a+1) - part[node].sum;
        if(a != b) {
            part[node*2].lazy += (ll)value;
            part[node*2+1].lazy += (ll)value;
        }
        return;
    }
    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);
    part[node].sum = part[node*2].sum + part[1+node*2].sum;
}

int main()
{
	int n,m,type,l,r;
    cin >> n >> m;
    build(1,1,n);
	for (int i = 0; i < m; ++i) {
		cin >> type >> l >> r;
		if(type == 0) update_tree(1,1,n,l,r,1);
		else if(type == 1) cout << query_sum(1,1,n,l,r) << endl;
	}
    return 0;
}
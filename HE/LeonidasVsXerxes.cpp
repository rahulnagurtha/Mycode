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

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};



struct tree {
	int inc;
	int dec;
	int longest;
};

tree seg[500001];

ll A[100005];

// Build with array [i,j]


tree combine_data(tree q1,tree q2,int i,int j) {
	tree send;
	int mid = (i+j)/2;
	send.longest = max(q1.longest,q2.longest);
	if(A[mid] < A[1+mid]) {
		send.longest = max(send.longest,q1.dec + q2.inc);
	}
	//setting inc
	if(q1.inc == (mid - i + 1) && A[mid] < A[1+mid]) {
		send.inc = q1.inc + q2.inc;
	}
	else send.inc = q1.inc;
	//setting dec
	if(q2.dec == (j - mid) && A[mid] < A[1+mid]) {
		send.dec = q2.dec + q1.dec;
	}
	else send.dec = q2.dec;
	return send;
}

void build(int node,int i,int j) {
	if(i>j) return;
	if(i==j) {						
		seg[node].longest = seg[node].dec = seg[node].inc = 1;
		return;
	}
	build(node*2,i,(i+j)/2);
	build(node*2+1,1+(i+j)/2,j);
	seg[node] = combine_data(seg[2*node],seg[2*node+1],i,j);
	return;
}


tree query(int node,int a,int b,int i,int j) {
	if(a >= i && b <= j) return seg[node];
	int mid = (a+b)/2;

	if(j <= mid) {
		return query(node*2, a, mid, i, j);
	}
	if(mid < i){
		return query(1+node*2, 1+mid, b, i, j);
	}
	tree q1,q2,tmp;
	q1 = query(node*2, a, mid, i, j);
	q2 = query(1+node*2, 1+mid, b, i, j);
	return combine_data(q1,q2,a,b);
}

void upd(int node,int pos,int i,int j) {
    if(i>j) return;
    if(i == j && i == pos) {			
        seg[node].longest = seg[node].dec = seg[node].inc = 1;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2);
        upd(2*node+1,pos,(i+j)/2 + 1,j);
        seg[node] = combine_data(seg[2*node],seg[2*node+1],i,j);
    	return;
    }
}

int main()
{
    int t;
    si(t);
    while(t--) {
    	int n,q;
    	int type,x,y;
    	si2(n,q);
    	for (int i = 1; i <= n; ++i) {
    		slli(A[i]);
    	}
    	build(1,1,n);
    	for (int i = 0; i < q; ++i) {
    		si3(type,x,y);
    		if(type == 1) {
    			A[x] += (ll)y;
    			upd(1,x,1,n);
    		}
    		else {
    			pi(query(1,1,n,x,y).longest);
    		}
    	}
    }
    return 0;
}
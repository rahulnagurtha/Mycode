#include <bits/stdc++.h>

using namespace std;


#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)


#define pi(i)                   printf("%d\n",i)

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


int a[1000002],b[1000002],cnt[1000002],lft[1000002],ryt[1000002];


struct tree {
	int sum;
};

tree seg[5000001];

// Build with array [i,j]

void build(int node,int i,int j) {
	if(i>j) return;
	if(i==j) {						
		seg[node].sum = 0;
		return;
	}
	build(node*2,i,(i+j)/2);
	build(node*2+1,1+(i+j)/2,j);
	seg[node].sum = seg[node*2].sum + seg[1+node*2].sum;
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
        seg[node].sum += val;
        return;
    }
    if(i<=pos&&j>=pos) {
        upd(2*node,pos,i,(i+j)/2,val);
        upd(2*node+1,pos,(i+j)/2 + 1,j,val);
        seg[node].sum = seg[2*node].sum + seg[1+2*node].sum;
    	return;
    }
}

int getint()
{
	int re=0;
	char c;
	for (c=getchar();c<'0'||c>'9';c=getchar());
	do
	{
		re=re*10+c-'0';
		c=getchar();
	}while(c<='9'&&c>='0');
	return re;
}




int main()
{
	ll ans = 0;
    int n,cur = 0,prev = 0,sz;
    si(n);
    for (int i = 0; i < n; ++i) {
    	si(a[i]);
    	b[i] = a[i];
    }
    
    //mapping of numbers
    sort(b, b+n);
    sz = unique(b, b + n) - b;
    for (int i = 0; i < n; i++) a[i] = lower_bound(b, b + sz, a[i]) - b;
    //mapping complete
    
    build(1,0,n);
    for (int i = 0; i < n; ++i) {
    	cnt[a[i]]++;
    	lft[i] = cnt[a[i]];
    }
    fill(cnt,0);
    for (int i = n-1; i >= 0; --i) {
    	cnt[a[i]]++;
    	ryt[i] = cnt[a[i]];
    }
    for (int i = n-1; i >= 0; --i) {
    	ans += qsum(1,0,n,0,lft[i]-1);
    	upd(1,ryt[i],0,n,1);
    }
    cout << ans << endl;
    return 0;
}
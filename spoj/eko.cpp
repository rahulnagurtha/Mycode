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

ll n,m,a[1000005],sum[1000005];

void preprocess() {
	sort(a+1,a+n+1);
	for (int i = 1; i <= n; ++i) sum[i] = a[i] + sum[i-1];
	return;
}


ll bsearch_again(ll l,ll r,ll h) {
	assert(l <= r);
	if(l == r) return l;
	ll mid = (l + r)/2;
	if(a[mid] > h) return bsearch_again(l,mid,h);
	else return bsearch_again(mid+1,r,h);
}

ll bsearch(ll l,ll r) {
	assert(l >= r);
	if(l == r) return l;
	ll mid = (l+r)/2 + (l+r)%2;
	ll canget,here;
	here = bsearch_again(1,n,mid);
	canget = sum[n] - sum[here - 1] - mid*(n - here + 1);
	if(canget >= m) return bsearch(l,mid);
	else return bsearch(mid-1,r);
}

int main()
{
	cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
	preprocess();
	cout << bsearch(a[n]-1,0) << endl;
    return 0;
}

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
#define MOD                     3
#define N 						100005

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

ll q,n;
ll l,r;
ll bSz;
ll type;
ll a[N];
ll expon[N];
ll block[320];

void init() {
	expon[0] = 1;
	for (ll i = 1; i < N; ++i) {
		expon[i] = (expon[i-1]*2) % MOD;
	}
	return;
}

void query1() {
	ll ans = 0;
	ll cnt = 0;
	ll lBlock,rBlock;
	cin >> l >> r;
	l++;r++;
	while(l%bSz != 1 && l <= r) {
		ans = (ans*2 + a[l]) % MOD;
		l++;
	}
	lBlock = ceil(l,bSz);
	rBlock = ceil(r,bSz);
	if(r%bSz != 0) rBlock--;
	for (ll i = lBlock; i <= rBlock; ++i) {
		ans = (ans*expon[bSz] + block[i]) % MOD;
	}
	if(l <= r) { 
		for (ll i = bSz*(rBlock) + 1; i <= r; ++i) {
			ans = (ans*2 + a[i]) % MOD;
		}
	}
	cout << ans%MOD << endl;
	return;
}

void query2() {
	ll idx;
	cin >> idx;
	idx++;
	if(a[idx] == 0) {
		a[idx] = 1;
		ll bNum = ceil(idx,bSz);
		block[bNum] = 0;
		for (ll i = 1+(bNum-1)*bSz; i <= min(n,bSz*bNum); ++i) {
			block[bNum] = (2*block[bNum] + a[i]) % MOD;
		}
	}
	return;
}


int main()
{
	SYNC;
    string tmp;
    init();
    cin >> n;
    cin >> tmp;
    bSz = (ll)sqrt(n);
    for (ll i = 0; i < tmp.size(); ++i) {
    	a[i + 1] = tmp[i] - '0';
    }
    for (ll i = 1; i < 320; ++i) {
    	block[i] = 0;
    	for (ll j = 1 + bSz*(i-1); j <= min(bSz*i,n); ++j) {
    		block[i] = (2*block[i] + a[j]) % MOD;
    	}
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
    	cin >> type;
    	if(type == 0) query1();
    	else query2();
    }
    return 0;
}
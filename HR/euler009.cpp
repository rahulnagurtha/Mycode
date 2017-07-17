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


ll bestTriple[100005];


ll check_and_return_perfect_square_root(ll src) {
	ll retVal = sqrt(src);
	if(retVal*retVal == src) return retVal;
	else return -1;
}

void pre_process() {
	for (ll a = 1; a <= 3000; ++a) {
		for (ll b = a + 1; b <= 3000; ++b) {
			ll c = check_and_return_perfect_square_root(a*a + b*b);
			if(c <= b) continue;
			bestTriple[a + b + c] = max(a*b*c,bestTriple[a + b + c]);
		}
	}
	return;
}




int main()
{
	fill(bestTriple,-1);
	pre_process();
    ll t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	ll n;
    	cin >> n;
    	ll ans = -1;
		ans = max(ans,bestTriple[n]);
    	cout << ans << endl;
    }
    return 0;
}
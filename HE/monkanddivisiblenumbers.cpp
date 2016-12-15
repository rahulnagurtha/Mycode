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

#define rep(i,a,b)              for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)              for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)           for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)           for(int i = (a); (i) >= (b); i -= (s))

#define SYNC                    ios_base::sync_with_stdio(0)
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


ll fast_exp(ll x, ll y)
{
    ll res = 1;     // Initialize result
  
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = res*x;
            res %= MOD;
        }
        // n must be even now
        y = y >> 1; // y = y/2
        x = x*x;  // Change x to x^2
    	x %= MOD;
    }
    return res;
}

template<class T> inline vector<pair<T, ll> > factorize(T n)
{
    vector<pair<T, ll> > R;
    for (T i = 2; n > 1;) {
        if (n % i == 0) {
            ll C = 0;
            for (; n % i == 0; C++, n /= i);
            R.push_back(make_pair(i, C));
        }
        i++;
        if (i > n / i) i = n;
    }
    if (n > 1) R.push_back(make_pair(n, 1));
    return R;
}



int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	ll a,b,c;
    	cin >> a >> b >> c;
    	VOLL A = factorize(a);
    	VOLL B = factorize(b);
    	for (int i = 0; i < B.size(); ++i) {
    		B[i].SS *= c;
    	}
    	// cout << A << endl;
    	// cout << B << endl;
    	for (int i = 0; i < A.size(); ++i) {
    		for (int j = 0; j < B.size(); ++j) {
    			if(A[i].FF == B[j].FF) {
    				B[j].SS -= A[i].SS;
    			}
    		}
    	}
    	ll ans = 1;
    	for (int i = 0; i < B.size(); ++i) {
    		ans = ans*fast_exp(B[i].FF,B[i].SS);
    		ans %= MOD;
    	}
    	cout << ans << endl;
    }
    return 0;
}
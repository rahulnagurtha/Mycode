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

template<class T> inline vector<pair<T, int> > factorize(T n)
{
    vector<pair<T, int> > R;
    for (T i = 2; n > 1;) {
        if (n % i == 0) {
            int C = 0;
            for (; n % i == 0; C++, n /= i);
            R.push_back(make_pair(i, C));
        }
        i++;
        if (i > n / i) i = n;
    }
    if (n > 1) R.push_back(make_pair(n, 1));
    return R;
}


ll PollardRho(ll number) {
	ll x_fixed = 2, cycle_size = 2, x = 2, factor = 1;

	while (factor == 1) {
		for (ll count = 1;count <= cycle_size && factor <= 1; count++) {
			x = (x*x+1)%number;
			factor = __gcd(x - x_fixed, number);
		}
		cycle_size *= 2;
		x_fixed = x;
	}
	return factor;
}

int main()
{
	// cout << PollardRho(100);
	ll n;
	cin >> n;
	// while(n > 1) {
	// 	ll tmp = PollardRho(n);
	// 	if(tmp == -1) tmp = n;
	// 	n = n/tmp;
	// 	cout << tmp << endl;
	// 	// cin >> tmp;
	// }
	cout << factorize(n);
	return 0;
}
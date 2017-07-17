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
 
 
 
VL lft;
VL ryt;
ll a[36];
ll ans;
ll n,k;
 
 
bool is_valid(ll cur,ll product_so_far) {
	return (cur <= (k/product_so_far));
}
 
void meet_in_the_middle() {
	int base = 1;
	int sz = n/2;
	for (int i = 1; i < (1 << sz); ++i) {
		ll tmp_product = 1;
		bool is_excess = false;
		for (int j = 0; j < sz; ++j) {
			if(i & (1 << j)) {
				if(!is_valid(a[j + base],tmp_product)) {
					is_excess = true;
					break;
				}
				tmp_product *= a[j + base];
			}
		}
		if(!is_excess) {
			ans++;
			lft.pb(tmp_product);
		}
	}
	sz = n - n/2;
	base = n/2 + 1;
	for (int i = 1; i < (1 << sz); ++i) {
		ll tmp_product = 1;
		bool is_excess = false;
		for (int j = 0; j < sz; ++j) {
			if(i & (1 << j)) {
				if(!is_valid(a[j + base],tmp_product)) {
					is_excess = true;
					break;
				}
				tmp_product *= a[j + base];
			}
		}
		if(!is_excess) {
			ans++;
			ryt.pb(tmp_product);
		}
	}
	if(lft.size() > 0) sort(lft.begin(), lft.end());
	if(ryt.size() > 0) sort(ryt.begin(), ryt.end());
	for (int i = 0; i < lft.size(); ++i) {
		// //do a binary search for a[i]
		vector<ll>::iterator it = upper_bound(ryt.begin(), ryt.end(), k/lft[i]);
		if(it == ryt.end()) {
			ans += ryt.size();
		}
		else ans += (it - ryt.begin());
	}
	cout << ans << endl;
	return;
}
 
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    if(n == 1) {
    	if(a[1] <= k) cout << "1" << endl;
    	else cout << "0" << endl;
    	return 0;
    }
    meet_in_the_middle();
    return 0;
}  
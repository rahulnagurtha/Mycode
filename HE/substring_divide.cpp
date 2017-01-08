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


ll to_int(string A) {
	ll val = 0;
	for (int j = 0; j < A.size(); ++j) {
		val = val*10 + (A[j] - '0');
	}
	return val;
}



int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	ll ans = 0;
    	ll n;
    	cin >> n;
    	string A;
    	cin >> A;
    	for (int sz = 1; sz <= 3; ++sz) {
    		for (int i = 0; i + sz <= A.size(); ++i) {
    			ll num = to_int(A.substr(i,sz));
    			if((num%8) == 0) {
    				if((num%3) != 0) ans++;
    			}
    		}
    	}
    	if(A.size() <= 3) {
    		cout << ans << endl;
    		continue;
    	}
    	ll lastThreeDigitValue = to_int(A.substr(1,3));
    	ll remainder[3];
    	fill(remainder,0);
    	remainder[((A[0] - '0') + (A[1] - '0') + (A[2] - '0') + (A[3] - '0')) % 3] = 1;
    	
    	if(((lastThreeDigitValue % 8) == 0) && ((lastThreeDigitValue % 3) != 0)) ans++; 
    	
    	for (int i = 4; i < A.size(); ++i) {
    		ll newValues[3];
    		fill(newValues,0);
			ll curDigit = (A[i] - '0') % 3;
			lastThreeDigitValue  = lastThreeDigitValue - (A[i-3] - '0')*100;
    		
    		lastThreeDigitValue = lastThreeDigitValue*10 + (A[i] - '0');
    		for (int k = 0; k < 3; ++k) {
    			newValues[(k + curDigit) % 3] += remainder[k];
    		}
    		newValues[((A[i] - '0') + (A[i - 1] - '0') + (A[i - 2] - '0') + (A[i - 3] - '0')) % 3]++;
    		for (int k = 0; k < 3; ++k) {
    			remainder[k] = newValues[k];
    		}
    		if((lastThreeDigitValue % 8) == 0) ans += (remainder[1] + remainder[2]);
    	}
    	cout << ans << endl;
    }
    return 0;
}
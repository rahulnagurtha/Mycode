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
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     100000000000007LL
#define N                     	100007


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

ll a[N];

int main()
{
	ll ans = MOD;
	ll n,x;
    // freopen("in.txt", "r", stdin);
    int lft = -2,ryt = -2;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    sort(a,a+n);
    if(n == 1) {
    	printf("0\n");
    	return 0;
    }
    //find left
    for (int i = 0; i < n; ++i) {
    	if(a[i] > x) {
    		lft = i - 1;
    		break;
    	}
    }
    if(lft == -2 || lft == -1) {
    	ans = 0;
    	if(lft == -1) {
			ans = (a[n-2] - x);
    	}
    	else {
			ans = (x - a[1]);
    	}
    	cout << ans << endl;
    	return 0;
    }
    //find right
    for (int i = 0; i < n; ++i) {
    	if(a[i] > x) {
    		ryt = i;
    		break;
    	}
    }
    if(ryt == -2 || ryt == 0) {
    	ans = 0;
    	if(ryt == 0) {
    			ans = (a[n-2] - x);
    	}
    	else {
			ans = (x - a[1]);
    	}
    	cout << ans << endl;
    	return 0;
    }
    //
    VL lftside;
    VL rytside;
    lftside.pb(0);
    rytside.pb(0);
    for (int i = ryt; i < n; ++i) {
    	rytside.pb(a[i] - x);
    }
    for (int i = lft; i >= 0; --i) {
    	lftside.pb(x - a[i]);
    }
    ans = min(ans,2*lftside.back() + rytside[rytside.size() - 2]);
    ans = min(ans,lftside.back() + 2*rytside[rytside.size() - 2]);
    ans = min(ans,rytside.back() + 2*lftside[lftside.size() - 2]);
    ans = min(ans,2*rytside.back() + lftside[lftside.size() - 2]);
    cout << ans << endl;
    return 0;
}
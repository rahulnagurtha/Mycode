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
#define MOD                     1000000007LL
#define INF 					INT_MAX
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






inline void Refresh() {
    
}


ll original[N];
ll a[N];
VL buckets[N];
VL extra;


int main()
{
	ll n,m,tmp;
	ll maxMin;
	cin >> n >> m;
	maxMin = n/m;
	for (ll i = 1; i <= n; ++i) {
		cin >> tmp;
		a[i] = original[i] = tmp;
		if(tmp <= m) buckets[tmp].pb(i);
		else extra.pb(i);
	}
	for (ll i = 1; i <= m; ++i) {
		while(extra.size() > 0 && buckets[i].size() < maxMin) {
			buckets[i].pb(extra.back());
			extra.pop_back();
		}
	}
	bool areAllHappy = true;
	for (int i = 1; i <= m; ++i) {
		if(buckets[i].size() < maxMin) {
			areAllHappy = false;
			break;
		}
	}
	if(!areAllHappy) {
		extra.clear();
		for (ll i = 1; i <= m; ++i) {
			if(buckets[i].size() > maxMin) {
				extra.pb(i);
			}
		}
		for (ll i = 1; i <= m; ++i) {
			while(buckets[i].size() < maxMin) {
				while(extra.size() > 0 && buckets[extra.back()].size() <= maxMin) {
					extra.pop_back();
				}
				buckets[i].pb(buckets[extra.back()].back());
				buckets[extra.back()].pop_back();
			}
		}
	}
	for (ll i = 1; i <= m; ++i) {
		for (ll j = 0; j < buckets[i].size(); ++j) {
			a[buckets[i][j]] = i;
		}
	}
	ll minCount = 0;
	for (ll i = 1; i <= n; ++i) {
		if(a[i] != original[i]) {
			minCount++;
		}
	}
	cout << maxMin << " " << minCount << endl;
	for (ll i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}
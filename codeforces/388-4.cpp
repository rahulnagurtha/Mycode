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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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
#define N                     	200007


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


ll n;
ll a,b,q,k;
VL bids[N];
map<ll,ll> data;

void process() {
	if(data.size() == 0) {
		cout << "0 0" << endl;
		return;
	}
	else {
		auto itFirstHighest = data.rbegin();
		++itFirstHighest;
		auto itSecondHighest = itFirstHighest;
		itFirstHighest--;
		if(itSecondHighest == data.rend()) {
			cout << itFirstHighest->SS << " " << bids[itFirstHighest->SS][0] << endl;
			return;
		}
		else {
			auto up = upper_bound(bids[itFirstHighest->SS].begin(),bids[itFirstHighest->SS].end(),itSecondHighest->FF);
			cout << itFirstHighest->SS << " " << *up << endl;
			return;
		}
	}
}


int main()
{
	ll tmp;
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		cin >> a >> b;
		bids[a].pb(b);
	}
	for (ll i = 1; i <= n; ++i) {
		if(bids[i].size() != 0) {
			data[bids[i].back()] = i;
		}
	}
	cin >> q;
	for (ll i = 0; i < q; ++i) {
		cin >> k;
		VL bin;
		for (ll j = 0; j < k; ++j) {
			cin >> tmp;
			bin.pb(tmp);
		}
		//remove
		for (ll j = 0; j < bin.size(); ++j) {
			if(bids[bin[j]].size() != 0) {
				data.erase(bids[bin[j]].back());
			}
		}
		process();
		for (ll j = 0; j < bin.size(); ++j) {
			if(bids[bin[j]].size() != 0) {
				data[bids[bin[j]].back()] = bin[j];
			}
		}
	}
    return 0;
}
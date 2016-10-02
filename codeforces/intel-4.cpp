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

VL X;
VL data[50005];
set<ll> all;
VL maxPossible;
unordered_set<ll> eleSelectedSoFar;
VL finalAnswer;

int main()
{
	ll n;
	ll tmp;
    slli(n);
    for (int i = 1; i <= n; ++i) {
    	slli(tmp);
    	X.pb(tmp);
    }
    sort(X.begin(),X.end());
    for (int i = 0; i < X.size(); ++i) {
    	tmp = X[i];
    	while(tmp >= 1) {
    		all.insert(tmp);
    		data[i+1].pb(tmp);
    		tmp = tmp >> 1;
    	}
    	reverse(data[i+1].begin(),data[i+1].end());
    }
    for (set<ll>::iterator it = all.begin(); it != all.end(); ++it) {
    	maxPossible.pb(*it);
    }
    ll l = 0,r = maxPossible.size() - 1;
    VL::iterator up;
    unordered_set<ll>::const_iterator got;
    while(l < r) {
    	ll mid = (l + r) >> 1;
    	tmp = maxPossible[mid];
    	// cout << tmp << endl;
    	eleSelectedSoFar.clear();
    	bool isPossible = true;
    	for (int i = n; i > 0; --i) {
    		// cout << data[i] ;
    		bool selectedAny = false;
    		ll ctr;
    		up = upper_bound(data[i].begin(),data[i].end(),tmp);
    		if(up == data[i].end()) ctr = data[i].size() - 1;
    		else {
    			ctr = up - data[i].begin();
    			while(ctr >= 0 && data[i][ctr] > tmp) {
    				ctr--;
    			}
    		}
    		// cout << " " << ctr << endl;
    		for (int j = ctr; j >= 0; --j) {
    			got = eleSelectedSoFar.find(data[i][j]);
    			if(got == eleSelectedSoFar.end()) {
    				selectedAny = true;
    				eleSelectedSoFar.insert(data[i][j]);
    				break;
    			}
    		}
    		if(!selectedAny) {
    			isPossible = false;
    			break;
    		}
    	}
    	if(isPossible) r = mid;
    	else l = mid + 1;
    }
    // cout << maxPossible[l] << endl;
    eleSelectedSoFar.clear();
	for (int i = n; i > 0; --i) {
		// cout << data[i] << " ";
		ll ctr;
		up = upper_bound(data[i].begin(),data[i].end(),maxPossible[l]);
		if(up == data[i].end()) ctr = data[i].size() - 1;
		else {
			ctr = up - data[i].begin();
			while(ctr >= 0 && data[i][ctr] > maxPossible[l]) {
				ctr--;
			}
		}
		// cout << data[i][ctr] << endl;
		for (int j = ctr; j >= 0; --j) {
			got = eleSelectedSoFar.find(data[i][j]);
			if(got == eleSelectedSoFar.end()) {
				finalAnswer.pb(data[i][j]);
				eleSelectedSoFar.insert(data[i][j]);
				break;
			}
		}
	}
	for (int i = 0; i < finalAnswer.size(); ++i) {
		printf("%I64d ",finalAnswer[i]);
	}
    return 0;
}
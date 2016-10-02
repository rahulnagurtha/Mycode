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

ll a[N];
ll X[N];

int main()
{
	bool diffFound = false;
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    ll lft,ryt;
    ll finalVal;
    ll toAdd;
    for (int i = 0; i + 1 < n; ++i) {
    	if(a[i] != a[i+1]) {
    		lft = min(a[i],a[i+1]);
    		ryt = max(a[i],a[i+1]);
    		diffFound = true;
    	}
    }
    if(!diffFound) {
    	cout << "YES" << endl;
    	return 0;
    }
    bool isPossible;
    //finalval = lft
    isPossible = true;
    finalVal = lft;
    for (int i = 0; i < n; ++i) {
    	X[i] = abs(finalVal - a[i]);
    }
    toAdd = 0;
    for (int i = 0; i < n; ++i) {
    	if(X[i] != 0) {
    		toAdd = X[i];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if(X[i] == 0) continue;
    	if(X[i] != toAdd) {
    		isPossible = false;
    		break;
    	}
    }
    if(isPossible) {
    	cout << "YES" << endl;
    	return 0;
    }


    //finalval = ryt
    isPossible = true;
    finalVal = ryt;
    // cout << "checking for " << ryt << endl;
    for (int i = 0; i < n; ++i) {
    	X[i] = abs(finalVal - a[i]);
    	// cout << i << " <> " << X[i] << endl;
    }
    toAdd = 0;
    for (int i = 0; i < n; ++i) {
    	if(X[i] != 0) {
    		toAdd = X[i];
    	}
    }
    // cout << "Toadd is " << toAdd << endl;
    for (int i = 0; i < n; ++i) {
    	if(X[i] == 0) continue;
    	if(X[i] != toAdd) {
    		// cout << "broken at " << i << endl;
    		isPossible = false;
    		break;
    	}
    }
    if(isPossible) {
    	cout << "YES" << endl;
    	return 0;
    }

    //finalval = mid
    isPossible = true;
    if((ryt + lft) % 2 != 0) {
    	cout << "NO" << endl;
    	return 0;
    }
    finalVal = (ryt + lft)/2;
    for (int i = 0; i < n; ++i) {
    	X[i] = abs(finalVal - a[i]);
    }
    toAdd = 0;
    for (int i = 0; i < n; ++i) {
    	if(X[i] != 0) {
    		toAdd = X[i];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if(X[i] == 0) continue;
    	if(X[i] != toAdd) {
    		isPossible = false;
    		break;
    	}
    }
    if(isPossible) {
    	cout << "YES" << endl;
    	return 0;
    }
    cout << "NO" << endl;
    return 0;
}
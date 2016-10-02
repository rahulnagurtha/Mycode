#include <bits/stdc++.h>

using namespace std;

#define INF 					INT_MAX
#define N                     	100007

typedef unsigned long long int ll;

ll n,extraAvailable;
ll a[N];
ll b[N];


bool canIMake(ll target) {
	ll extraRequired = 0;
	for (ll i = 0; i < n; ++i) {
		if(a[i]*target > b[i]) extraRequired += (a[i]*target - b[i]);
	}
	assert(extraRequired >= 0);
	return (extraRequired <= extraAvailable);
}


int main()
{
    ll minimumPossible = INF;
    ll extra = 0;
    cin >> n >> extraAvailable;
    for (ll i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
    	cin >> b[i];
    }
    for (ll i = 0; i < n; ++i) {
    	minimumPossible = min(minimumPossible,b[i]/a[i]);
    }
    for (int i = 0; i < n; ++i) {
    	b[i] = b[i] - minimumPossible*a[i];
    }
    ll l = 1,r = extraAvailable;
    while(l <= r) {
    	ll mid = (l + r)/2;
    	if(canIMake(mid)) {
    		extra = mid;
    		l = mid + 1;
    	}
    	else {
    		r = mid - 1;
    	}
    }
    cout << minimumPossible + extra << endl;
    return 0;
}
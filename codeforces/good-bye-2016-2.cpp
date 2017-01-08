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

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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


int main()
{
	int n;
	cin >> n;
	int cur = 0;
	string dir;
	int t;
	for (int i = 0; i < n; ++i) {
		// cout << cur << endl;
		cin >> t >> dir;
		if(cur == 0) {
			if(dir != "South") {
				cout << "NO" << endl;
				return 0;
			}
		}
		if(cur == 20000) {
			if(dir != "North") {
				cout << "NO" << endl;
				return 0;
			}
		}
		if((dir == "East") || (dir == "West")) continue;
		t %= 40000;
		// if((cur == 0) && (i != 0)) continue;
		if(dir == "South") {
			int d1 = 20000 - cur;
			int d2 = 20000;
			int d3 = cur;
			// cout << d1 << " " << d2 << " " << d3 << endl;
			if(t <= d1) {
				cur += t;
			}
			else if(t <= d1 + d2) {
				cur = 20000 - (t - d1);
			}
			else {
				cur = (t - d1 - d2);
			}

		}
		else {
			int d1 = cur;
			int d2 = 20000;
			int d3 = 20000 - cur;
			// cout << d1 << " " << d2 << " " << d3 << endl;
			if(t <= d1) {
				cur -= t;
			}
			else if(t <= d1 + d2) {
				cur = (d2 - (t - d1));
			}
			else {
				cur = 20000 - (t - d1 - d2);
			}
		}
	}
	if(cur == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
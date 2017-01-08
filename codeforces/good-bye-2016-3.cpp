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
#define N                     	300007


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


int a[N], delta[N], division[N];
const ll inf = 1e18;
string notPossible = "Impossible";


inline int helper(int x, int y){
    if(x == 1) {
    	if(y == 2) return 0;
    	else return 2;
    }
    else {
    	if(y == 1) return 1;
    	else return 3;
	}
}




int main()
{
	SYNC;
	int n;
	cin >> n;
	ll L = -inf, R = inf;
	for (int i = 0; i < n; ++i) {
	 	cin >> delta[i] >> division[i];
	} 
	delta[n] = 0; 
	division[n] = division[n-1];
	ll val = 0;
	ll t_value = 0;
	if(division[0] == 1) L = 1900;
	else R = 1900;
	for (int i = 0; i < n - 1; ++i) {
		int m = helper(division[i], division[i+1]);
		val = delta[i];
		t_value += val;
		if(m == 0){
			if(val > 0){
				cout << notPossible << endl;
				return 0;
			}
			R = min(R, 1900 - t_value);
		}
		else if(m == 1){
			if(val<0){
				cout << notPossible << endl;
				return 0;
			}
			L = max(L, 1900 - t_value);
		}
		else if(m == 2){
			L = max(L, 1900 - t_value);
			continue;
		}
		else if(m == 3){
			R = min(R, 1900 - t_value);
		}
	}
	if(L >= R){
		cout << notPossible << endl;
		return 0;
	}
	if(R == inf) {
		cout << "Infinity" <<endl;
		return 0;
	}
	t_value += delta[n-1];
	cout << R - 1 + t_value << endl;
	return 0;
}
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


inline void Refresh() {
    
}

ll n;
ll parent[N];
ll curWater[N];
ll capacity[N];


ll add(ll quantity,ll pos) {
	if(pos == n) {
		curWater[pos] = min(curWater[pos] + quantity,capacity[pos]);
		return n;
	}
	if(curWater[pos] + quantity <= capacity[pos]) {
		curWater[pos] += quantity;
		return pos;
	}
	else {
		parent[pos] = add(quantity - capacity[pos] + curWater[pos],max(pos + 1,parent[pos]));
		curWater[pos] = capacity[pos];
		return parent[pos];
	}
}


int main()
{
	SYNC;
	cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> capacity[i];
    	curWater[i] = 0;
    	parent[i] = i;
    }
    ll q,type,k,p,x;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
    	cin >> type;
    	if(type == 1) {
    		cin >> p >> x;
    		add(x,p);
    	}
    	else {
    		cin >> k;
    		cout << curWater[k] << endl;
    	}
    }
    return 0;
}
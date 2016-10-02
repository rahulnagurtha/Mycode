#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

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

class MonstersValley2
{
	VI body;
	VI cost;
public:
	int minCost(ll strength,int idx) {
		if(idx == body.size() - 1) return (strength >= body[idx] ? 0 : cost[idx]);
		if(strength >= body[idx]) {
			return min(cost[idx] + minCost(strength + (ll)body[idx],idx+1),minCost(strength,idx+1));
		}
		else {
			return cost[idx]+minCost(strength + (ll)body[idx],idx+1);
		}
	}
	int minimumPrice(VI dread,VI price ) {
		body = dread;
		cost = price;
		return minCost(0,0);
	}
};
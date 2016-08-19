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

class PowerOfThreeEasy
{
	ll power[25];
	ll x2,y2;
public:
	bool isPossible(ll x1,ll y1,ll k) {
		if(x1 == 538002 && y1 == 64032079) printf("here\n");
		if((x1 > x2) || (y1 > y2)) return false;
		if((x1 == x2) && (y1 == y2)) return true;
		return (isPossible(x1 + power[k],y1,k+1) || isPossible(x1,y1 + power[k],k+1));
	}
	string ableToGet(int x, int y) {
		x2 = x;
		y2 = y;
		power[0] = 1;
		for (ll i = 1; i < 25; ++i) {
			power[i] = power[i-1]*3;
		}
		return (isPossible(0,0,0) ? "Possible" : "Impossible");
	}
};

int main() {
	PowerOfThreeEasy test;
	int x,y;
	cin >> x >> y;
	cout << test.ableToGet(x,y) << endl;
}
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

class TaroFriends
{
public:
	bool ispossible(int lft,int ryt,VI points,int X) {
		if(lft > ryt) swap(lft,ryt);
		bool canGoLeft,canGoRyt;
		for (int i = 0; i < points.size(); ++i) {
			canGoRyt = canGoLeft = false;
			if((lft <= points[i] + X) && (points[i] + X <= ryt)) {
				canGoLeft = true;
			}
			if((lft <= points[i] - X) && (points[i] - X <= ryt)) {
				canGoRyt = true;
			}
			if (!canGoLeft && !canGoRyt) {
				return false;
			}
		}
		return true;
	}
	int getNumber(VI coordinates,int X) {
		int ans = INT_MAX;
		int lft,ryt;
		sort(coordinates.begin(),coordinates.end());
		for (int i = 0; i < coordinates.size(); ++i) {
			for (int j = i + 1; j < coordinates.size(); ++j) {
				lft = coordinates[i];
				ryt = coordinates[j];
				if(ispossible(lft + X,ryt + X,coordinates,X)) {
					ans = min(ans,abs(lft-ryt));
				}
				if(ispossible(lft - X,ryt - X,coordinates,X)) {
					ans = min(ans,abs(lft-ryt));
				}
				if(ispossible(lft + X,ryt - X,coordinates,X)) {
					ans = min(ans,abs(lft - ryt + 2*X));
				}
				if(ispossible(lft - X,ryt + X,coordinates,X)) {
					ans = min(ans,abs(ryt - lft + 2*X));
				}
			}
		}
		if(coordinates.size() == 1) ans = 0;
		return ans;
	}
};